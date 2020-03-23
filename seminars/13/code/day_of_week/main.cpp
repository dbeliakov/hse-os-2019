#include <iostream>
#include <ctime>

int main ()
{
  time_t rawtime;                                       // тип данных для хранения количества секунд
  struct tm * timeinfo;                                 // структура даты и времени
  int year, month ,day;

  char * weekday[] = { "Воскресенье", "Понедельник",
                       "Вторник", "Среда",
                       "Четверг", "Пятница", "Суббота"};

  //Ввод даты
  std::cout << "Введите год: ";    std::cin >> year;
  std::cout << "Введите месяц: "; std::cin >> month;
  std::cout << "Введите день: ";   std::cin >> day;

  // получить текущую информацию о дате и изменить её относительно введенной
  time( &rawtime );                              // текущая дата в секундах
  timeinfo = localtime( &rawtime );              // преобразовние текущей даты из секунд к нормальному виду
  timeinfo->tm_year = year - 1900;               // корректируем год
  timeinfo->tm_mon = month - 1;                  // корректируем значение месяца
  timeinfo->tm_mday = day;                       // введённый день

  mktime( timeinfo );                            // определить день недели

  std::cout << "День недели: " <<  weekday[timeinfo->tm_wday] << std::endl;

  return 0;
}
