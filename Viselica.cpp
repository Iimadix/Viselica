#include <iostream>
#include <string>   // Библиотека для более удобной работы со строками
#include <ctime>    // 

// База слов
const int RU_WORDS_COUNT = 5;
const int EN_WORDS_COUNT = 5;

const char* ru_words_database[RU_WORDS_COUNT] = { "яблоко", "банан", "вишня", "виноград", "апельсин" };
const char* en_words_database[EN_WORDS_COUNT] = { "apple", "banana", "cherry", "grape", "orange" };


// Выбор сложности
void chooseDifficulty()
{
    std::cout << "Выберите уровень сложности (1 - Легкий, 2 - Средний, 3 - Тяжелый): ";
    int difficulty;
    std::cin >> difficulty;
    // Обработка выбора сложности

}

// Функция для выбора случайного слова в зависимости от языка
const char* getRandomWord(int language)
{
    std::srand(std::time(0)); // Инициализация генератора случайных чисел

    // Русский
    if (language == 1)
    {
        int randomIndex = std::rand() % RU_WORDS_COUNT;
        return ru_words_database[randomIndex];
    }
    // Английский
    else if (language == 2)
    {
        int randomIndex = std::rand() % EN_WORDS_COUNT;
        return en_words_database[randomIndex];
    }
    else
    {
        std::cout << "Неверный выбор языка. Используется русский язык по умолчанию.\n";
        int randomIndex = std::rand() % RU_WORDS_COUNT;
        return ru_words_database[randomIndex];
    }
}

// Подсчет времени
void startTimer()
{
    // Реализация таймера (начало отсчета)
}

void stopTimer()
{
    // Реализация таймера (конец отсчета)
}

// Меню пользователя
void showMenu()
{
    std::cout << "\t\t\t\tДобро пожаловать в нашу версию игры \"Виселица\"\n\n";
    std::cout << "Пожалуйста выберите, ваше действие:\n";
    std::cout << "1. Начать игру\n";
    std::cout << "2. Выход\n";
    std::cout << "Ваш выбор: ";
}

// Визуал
void drawHangman(int attempts)
{
    switch (attempts)
    {
    case 6: std::cout << "  -----\n |     |\n       |\n       |\n       |\n       |\n-------\n"; break;
    case 5: std::cout << "  -----\n |     |\n O     |\n       |\n       |\n       |\n-------\n"; break;
    case 4: std::cout << "  -----\n |     |\n O     |\n |     |\n       |\n       |\n-------\n"; break;
    case 3: std::cout << "  -----\n |     |\n O     |\n/|     |\n       |\n       |\n-------\n"; break;
    case 2: std::cout << "  -----\n |     |\n O     |\n/|\\    |\n       |\n       |\n-------\n"; break;
    case 1: std::cout << "  -----\n |     |\n O     |\n/|\\    |\n/      |\n       |\n-------\n"; break;
    case 0: std::cout << "  -----\n |     |\n O     |\n/|\\    |\n/ \\    |\n  DEAD |\n-------\n"; break;
    }
}
// Функция выбора языка

int chooseLanguage()
{
    std::cout << "Выберите язык слова:\n";
    std::cout << "1. Русский\n";
    std::cout << "2. Английский\n";
    std::cout << "Ваш выбор: ";
    int language;
    std::cin >> language;
    return language;
}

// Совместная игра
void multiplayerMode()
{
    // Реализация режима, где один игрок загадывает слово, а другой угадывает
}

// Бонусные приколы
void bonusFeatures()
{
    // Возможность открыть букву или получить право на ошибку
}

// Выбор темы слов
void chooseWordTheme()
{
    // Реализация выбора темы
}

// Ачивки/рейтинг
void achievementsOrRating()
{
    // Выбор между системой ачивок или рейтинга
}

// Основная логика игры
void playGame()
{
    int language = chooseLanguage(); // Выбор языка
    const char* word = getRandomWord(language); // Получение случайного слова

    // Преобразуем слово в строку для удобной работы
    std::string wordToGuess(word);
    int wordLength = wordToGuess.length();

    // Строка для отображения угаданных букв
    std::string guessedWord(wordLength, '_');
    // Строка для отслеживания уже введенных букв
    std::string guessedLetters;

    int attempts = 6; // Максимальное количество попыток

    std::cout << "Загаданное слово (для теста): " << wordToGuess << "\n";
    std::cout << "Попробуйте угадать слово!\n";

    // Игра продолжается, пока есть попытки и не угадано слово
    while (attempts > 0 and guessedWord != wordToGuess)
    {
        std::cout << "\nСлово: " << guessedWord << "\n";
        std::cout << "Оставшиеся попытки: " << attempts << "\n";
        std::cout << "Введите букву: ";

        char guess;
        std::cin >> guess;

        // Проверка, была ли буква уже угадана
        if (guessedLetters.find(guess) != std::string::npos)
        {
            std::cout << "Вы уже вводили эту букву!\n";
            continue;
        }

        guessedLetters += guess; // Добавляем букву в строку угаданных букв

        // Проверка, есть ли буква в слове
        bool correctGuess = false;
        for (int i = 0; i < wordLength; ++i)
        {
            if (wordToGuess[i] == guess)
            {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        // Если буква не была угадана, уменьшаем количество попыток
        if (!correctGuess)
        {
            attempts--;
            drawHangman(attempts);
        }
    }

    // Вывод результата
    if (guessedWord == wordToGuess)
    {
        std::cout << "Поздравляем! Вы угадали слово: " << wordToGuess << "\n";
    }
    else
    {
        std::cout << "Вы проиграли. Загаданное слово было: " << wordToGuess << "\n";
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    // Меню и управление
    showMenu();
    int choice;
    std::cin >> choice;

    if (choice == 1)
    {
        // Запуск игры
        playGame();
    }

    else {
        std::cout << "До свидания!\n";
    }
}
