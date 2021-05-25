#include "mainWindow.h"
#include "ui_mainWindow.h"

QString nameClients[6];
int readyClients[6] = {2,-1,-1,-1,-1,-1};
QString PlayerName = "";
int PlayerIndex = -1;
int countConnectedPlayers = 0;

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    gameWin = new gameWindow();
    connect(gameWin, &gameWindow::firstwindow, this, &mainWindow::show);

    setIsConnect(false);
    setIsCreateGame(false);

    connect(&clientThread, &QThread::started, &clientSocket, &MySocket::clientRecvSock);
    connect(&clientSocket, &MySocket::clientListenSock, this, &mainWindow::clientReceiveSock);
    clientSocket.moveToThread(&clientThread);
}

mainWindow::~mainWindow()
{
    delete ui;
}

int getStatus (QString msg) // получить статус
{
    int status = -1;
    QString statusString = "";
    for (int i = 0; i < 4; i++)
    {
        if (msg[i] == ':') break;
        if (msg[i] == '0' || msg[i] == '1' || msg[i] == '2' || msg[i] == '3' || msg[i] == '4' || msg[i] == '5' || msg[i] == '6' || msg[i] == '7' || msg[i] == '8' || msg[i] == '9')
        statusString += msg[i];
    }
    if (statusString != "") status = statusString.toInt();
    return status;
}

QString getMessage (QString msg) //получить сообщение
{
    QString nonStatus;
    bool firstDblDot = false;
    for (int i = 0; i < msg.length(); i++)
    {
        if (!firstDblDot && msg[i] == ':')
        {
            firstDblDot = true;
            continue;
        }
        if (firstDblDot) nonStatus += msg[i];
    }
    return nonStatus;
}

void setReadyClient(int index)
{
    if (readyClients[index] == 0) readyClients[index] = 1;
    else if (readyClients[index] == 1) readyClients[index] = 0;
}

void mainWindow::on_shutdownWindow_clicked()
{
    this->close();
}

void mainWindow::on_backMenuWindow_clicked()
{
    setIsConnect(false);
    setIsCreateGame(false);
    //Закрываем поток
    clientSocket.setClientRunSock(false);
    clientThread.terminate();
    //Отключение от сервера
    clientSocket.clientDisconnect();

    this->ui->stackedWidget->setCurrentIndex(0);
}

void mainWindow::on_connectGameButton_clicked()
{
    if (IsConnect())
    {
        //предупреждение о том, что клиент уже подключен к серверу
        return;
    }
    else
    {
        //Подключение к серверу
        if (clientSocket.connectToServer())
        {
            setIsCreateGame(false);
            ui->startGameButton->setText("Не готов");
            setIsConnect(true);
            clientSocket.setClientRunSock(true);
            clientThread.start();

            this->ui->stackedWidget->setCurrentIndex(1);
        }
        else
        {
            //Предупреждение об ошибки подключения
            return;
        }
    }
}

void mainWindow::on_runGameButton_clicked()
{
    if (IsConnect())
    {
        //предупреждение о том, что клиент уже подключен к серверу
        return;
    }
    else
    {
        //Подключение к серверу
        if (clientSocket.connectToServer())
        {
            setIsCreateGame(true);
            ui->startGameButton->setText("Начать перестройку");
            setIsConnect(true);
            clientSocket.setClientRunSock(true);
            clientThread.start();

            this->ui->stackedWidget->setCurrentIndex(1);
        }
        else
        {
            //Предупреждение об ошибки подключения
            return;
        }
    }
}

void mainWindow::clientReceiveSock(QString text)
{
    int status = getStatus(text);
    QString message = getMessage(text);
    QString name;
    int count;
    switch(status)
    {
    case 8: //Обновление готовности игроков
        for (int i = 0; i < countConnectedPlayers; i++)
        {
            if (nameClients[i] == message)
            {
                setReadyClient(i);
                qDebug() << "PLAYER: " << nameClients[i] << ";  STATUS: " << readyClients[i];
                break;
            }
        }
        ui->listPlayers->setPlainText("");
        for (int i = 0; i < countConnectedPlayers; i++)
        {
            switch (readyClients[i])
            {
            case 2:
                ui->listPlayers->setTextColor("red");
                ui->listPlayers->insertPlainText(nameClients[i] + '\n');
                break;
            case 0:
                ui->listPlayers->setTextColor("blue");
                ui->listPlayers->insertPlainText(nameClients[i] + '\n');
                break;
            case 1:
                ui->listPlayers->setTextColor("green");
                ui->listPlayers->insertPlainText(nameClients[i] + '\n');
                break;
            case -1:
                qDebug() << "ОШИБКА В ПОДСЧЕТЕ КОЛИЧЕСТВА ПОДКЛЮЧЕНИЙ (8): " << countConnectedPlayers;
                break;
            default:
                qDebug() << "НЕ ПОНЯТНОЕ ЗНАЧЕНИЕ В МАССИВЕ ГОТОВНОСТИ ИГРОКОВ (8): " << readyClients[i];
                break;
            }
        }
        break;

    case 9: //Обновление списка игроков добавлении игроков и смены имени
        name = "";
        count = 0;
        ui->listPlayers->setPlainText("");
        for (int i = 0; i < message.length(); i++)
        {
            if (message[i] == ':')
            {
                switch (readyClients[count])
                {
                case 2:
                    nameClients[count] = name;
                    ui->listPlayers->setTextColor("red");
                    break;
                case 1:
                    nameClients[count] = name;
                    ui->listPlayers->setTextColor("green");
                    break;
                case 0:
                    nameClients[count] = name;
                    ui->listPlayers->setTextColor("blue");
                    break;
                case -1:
                    readyClients[count] = 0;
                    nameClients[count] = name;
                    ui->listPlayers->setTextColor("blue");
                    break;
                default:
                    qDebug() << "ОБНОВЛЕНИЕ СПИСКА ИГРОКОВ ПРОШЛО НЕ ГЛАДКО (9)";
                    break;
                }
//                nameClients[count] = name;
//                if (count == 0)
//                {
//                    readyClients[count] = 2;
//                    ui->listPlayers->setTextColor("red");
//                }
//                else
//                {
//                    readyClients[count] = 0;
//                    ui->listPlayers->setTextColor("blue");
//                }
                name = "";
                ui->listPlayers->insertPlainText(nameClients[count] + '\n');
                count++;
                continue;
            }
            name += message[i];
        }
        countConnectedPlayers = count;
        if (PlayerName == "" && PlayerIndex == -1)
        {
            PlayerName = nameClients[count - 1];
            PlayerIndex = count - 1;
            qDebug() << PlayerName << " " << PlayerIndex;
        }
        break;
    }
}

void mainWindow::on_startGameButton_clicked()
{
    QString message;
    if (IsCreateGame())
    {
        //проверки на готовность игроков

        //переход в игру
        gameWin->show();
        this->close();
    }
    else
    {
        if (ui->startGameButton->text() == "Не готов")
        {
            //Игрок готов к игре
            message = "8:" + PlayerName;
            clientSocket.clientSendSock(message);

            ui->startGameButton->setText("Готов");
            ui->nicknameEdit->setEnabled(false);
            ui->nicknameEditButton->setEnabled(false);
            ui->backMenuWindow->setEnabled(false);
        }
        else
        {
            //Игрок не готов к игре
            message = "8:" + PlayerName;
            clientSocket.clientSendSock(message);

            ui->startGameButton->setText("Не готов");
            ui->nicknameEdit->setEnabled(true);
            ui->nicknameEditButton->setEnabled(true);
            ui->backMenuWindow->setEnabled(true);
        }

    }
}

void mainWindow::on_nicknameEditButton_clicked()
{
    PlayerName = ui->nicknameEdit->text();
    QString message = "9:" + ui->nicknameEdit->text();
    if (message == "") return;
    ui->nicknameEdit->setText("");
    clientSocket.clientSendSock(message);
    Sleep(10);
    //Необходимо добавить проверку на одинаковые имена
}
