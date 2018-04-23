### **Тестовое задание на позицию C++ разработчика**

#### **Техническое задание:**
[TestTask.txt](https://github.com/NidentalEgor/Unzipper/blob/master/TestTask.txt)

#### **Получение:**
```sh
git clone --recursive https://github.com/NidentalEgor/Unzipper
```
#### **Сборка:**
Собирается с помощью Visual Studio 2015 и gcc 5.4.0.
```sh
cd Unzipper/Build
cmd windows.cmd / bash linux.sh
```

#### **Зависимости:**
Необходимо наличие Qt(разработка велась с использованием версии 5.7).

#### **Описание:**
Unzipper - приложение, реализующее техническое задание.
Zipper - вспомогательное приложение для создания архивов. Для дополнительной информации см.
```sh
Zipper --help
```

Для корректной работы под Linux необходимо заменить архив Unzipper/Unzipper/Resources/archive.zip
на аналогичный(для запаковки должен использоваться Zipper), содержащий исполняемый файл
game.exe, который может запускаться под Linux.