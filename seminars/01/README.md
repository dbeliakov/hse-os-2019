# Семинар 1. Основы работы в Linux

[Презентация](https://dbeliakov.github.io/hse-os-2019/seminars/01/slides/)  
[Примеры кода](code)  
[Пример файла конфигурации vim](.vimrc)  
[VirtualBox](https://www.virtualbox.org/)  
[Подготовленный образ для VirtualBox](https://yadi.sk/d/BPk8yhPEJ-qhjg)  
[PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html)  

### Параметры подготовленного образа
 * Операционная система: **Ubuntu Server 16.04.6 (32 bit)**
 * Предустановленные пакеты: **только для двух первых семинаров**
 * Имя обычного пользователя: **student**
 * Пароль обычного пользователя: **student**
 * Пароль пользователя root: **student**
 * Статический IP-адрес внутренней сети: **192.168.56.105**

### Создание виртуальной машины

Предполагается, что образ системы уже скачан и распакован.

`Machine`->`New...`. После этого указать параметры `Type: Linux`, `Version: Ubuntu (32-bit)`.
Памяти нам достаточно 1024 Мбайт. Не создавать виртуальный диск, а использовать существующий,
затем выбрать файл образа.

Используется PAE-ядро с поддержкой SMP, поэтому необходимо отметить флаги в `System`->`Motherboard` и `System`->`Processor`:

 * `Enable I/O APIC`
 * `Enable PAE/NX`


### Настройка внутренней сети
 Для доступа к виртуальной машине необходимо настроить дополнительный сетевой адаптер, связанный с внутренней сетью VirtualBox:
 `File`->`Preferences...`->`Network`->`Host-only networks`->`Значок "Добавить"`

 После этого нужно ввести параметры (или проверить параметры по умолчанию):

 ```
 IPv4 Address: 192.168.56.1
 IPv4 Network Mask: 255.255.255.0
 ```

 DHCP-сервер **не** нужен.

 После этого - включить виртуальный сетевой адаптер, если он не включен, а в настройках
 созданной виртуальной машины `Network`->`Adapter 2`:
   * Отметить `Enable Network Adapter`
   * Attached to: `Host-only Adapter`
   * Advanced -> Отметить `Cable Connected`

 В случае правильной настройки сети, по адресу [http://192.168.56.105](http://192.168.56.105)
должна загрузиться страница "Welcome to nginx!".

### Тренировка написания shell-скриптов

Написать shell-скрипт, который выполняет очистку "мусорных" файлов в соответствии с набором заданных шаблонов имен. Скрипт должен принимать один аргумент: имя каталога, который необходимо очистить; набор шаблонов передается скрипту в виде потока ввода.

При реализации нужно использовать циклы и условия. Использование команды find запрещено!

Шаблоны задаются в текстовом виде: каждый шаблон - на отдельной строке. Входной поток может содержать "комментарии" - строки, начинающиеся с символа #.

### Освоение командной строки

Пройти как можно больше уровней в игре [Bandit](http://overthewire.org/wargames/bandit/).

### Дополнительные материалы
* [История развития Linux](http://storage.piter.com/upload/contents/978591180807/978591180807_p.pdf)
* [Фильм RevolutionOS о появлении свободного ПО и Linux](https://www.youtube.com/watch?v=n1F_MfLRlX0)
* [Шпаргалка по работа в командной строке](https://help.ubuntu.ru/wiki/%D0%BA%D0%BE%D0%BC%D0%B0%D0%BD%D0%B4%D0%BD%D0%B0%D1%8F_%D1%81%D1%82%D1%80%D0%BE%D0%BA%D0%B0)
* [Шпаргалка по tmux](https://habr.com/post/126996/)
* [Права доступа в Linux](http://www.k-max.name/linux/prava-dostupa-v-linux-eshhe-odna-malenkaya-shpargalka/)
* [Как запускаются исполняемые файлы в Linux](http://www.k-max.name/linux/kak-zapuskayutsya-ispolnyaemye-fajly-v-linux/)
* [Midnight Commander: команды и горячие клавиши](http://mydebianblog.blogspot.com/2011/01/midnight-commander.html)
* [Основы работы с vim](http://mydebianblog.blogspot.com/2012/03/vim.html)
* [Основы работы с nano](https://help.ubuntu.ru/wiki/nano)
* [Основы bash. Часть 1](https://habr.com/post/47163/) и [Основы bash. Часть 2](https://habr.com/post/52871/)
