#include <iostream>
#include <string>
#include <ctime>

// База слов для русского языка
const int RU_WORDS_COUNT_EASY = 5;
const int RU_WORDS_COUNT_MEDIUM = 5;
const int RU_WORDS_COUNT_HARD = 5;

const char* ru_words_easy[RU_WORDS_COUNT_EASY] = { "кот", "дом", "лес", "мир", "сок" };
const char* ru_words_medium[RU_WORDS_COUNT_MEDIUM] = { "яблоко", "банан", "вишня", "дерево", "собака" };
const char* ru_words_hard[RU_WORDS_COUNT_HARD] = { "программирование", "компьютер", "интеллект", "механизм", "автомобиль" };

// База слов для английского языка
const int EN_WORDS_COUNT_EASY = 5;
const int EN_WORDS_COUNT_MEDIUM = 5;
const int EN_WORDS_COUNT_HARD = 5;

const char* en_words_easy[EN_WORDS_COUNT_EASY] = { "cat", "dog", "sun", "car", "pen" };
const char* en_words_medium[EN_WORDS_COUNT_MEDIUM] = { "apple", "banana", "cherry", "grape", "orange" };
const char* en_words_hard[EN_WORDS_COUNT_HARD] = { "programming", "computer", "intelligence", "mechanism", "automobile" };

// Глобальные переменные для выбора сложности
int chosenDifficulty = 1;

// Выбор сложности
void chooseDifficulty()
{
    std::cout << "Выберите уровень сложности (1 - Легкий, 2 - Средний, 3 - Тяжелый): ";
    std::cin >> chosenDifficulty;

    if (chosenDifficulty < 1 || chosenDifficulty > 3) {
        std::cout << "Неверный выбор. Устанавливается уровень сложности по умолчанию (Легкий).\n";
        chosenDifficulty = 1;
    }
}

// Функция для выбора случайного слова в зависимости от языка и сложности
const char* getRandomWord(int language)
{
    std::srand(std::time(0));

    // Русский язык
    if (language == 1)
    {
        switch (chosenDifficulty)
        {
        case 1: {
            int randomIndex = std::rand() % RU_WORDS_COUNT_EASY;
            return ru_words_easy[randomIndex];
        }
        case 2: {
            int randomIndex = std::rand() % RU_WORDS_COUNT_MEDIUM;
            return ru_words_medium[randomIndex];
        }
        case 3: {
            int randomIndex = std::rand() % RU_WORDS_COUNT_HARD;
            return ru_words_hard[randomIndex];
        }
        }
    }
    // Английский язык
    else if (language == 2)
    {
        switch (chosenDifficulty)
        {
        case 1: {
            int randomIndex = std::rand() % EN_WORDS_COUNT_EASY;
            return en_words_easy[randomIndex];
        }
        case 2: {
            int randomIndex = std::rand() % EN_WORDS_COUNT_MEDIUM;
            return en_words_medium[randomIndex];
        }
        case 3: {
            int randomIndex = std::rand() % EN_WORDS_COUNT_HARD;
            return en_words_hard[randomIndex];
        }
        }
    }

    // Если выбран неверный язык
    std::cout << "Неверный выбор языка. Используется русский язык по умолчанию.\n";
    int randomIndex = std::rand() % RU_WORDS_COUNT_EASY;
    return ru_words_easy[randomIndex];
}


// Переменные для хранения времени
std::time_t start_time;
std::time_t stop_time;


// Подсчет времени
void startTimer()
{
    start_time = std::time(nullptr);  // Фиксируем текущее время
}

void stopTimer()
{
    stop_time = std::time(nullptr);  // Фиксируем текущее время
    double elapsed_time = std::difftime(stop_time, start_time);  // Вычисляем разницу во времени
    std::cout << "Вы затратили времени: " << elapsed_time << " секунд.\n";
}

// Меню пользователя
void showMenu()
{
    std::cout << "\t\t\tДобро пожаловать в игру \"Виселица\"\n\n";
    std::cout << "Пожалуйста, выберите режим игры:\n";
    std::cout << "1. Обычная игра\n";
    std::cout << "2. Мультиплеер\n";
    std::cout << "3. Выход\n";
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
    std::cout << "Мультиплеер: Первый игрок загадывает слово, второй отгадывает.\n";

    // Ввод слова первым игроком
    std::string wordToGuess;
    std::cout << "Первый игрок, введите слово для отгадывания: ";
    std::cin >> wordToGuess;

    // Очистка консоли для второго игрока
    std::cout << std::string(50, '\n');  // Создаёт пустые строки, чтобы скрыть слово

    int wordLength = wordToGuess.length();
    std::string guessedWord(wordLength, '_');
    std::string guessedLetters;
    int attempts = 6;

    std::cout << "Второй игрок, попробуйте угадать слово!\n";

    startTimer();

    while (attempts > 0 && guessedWord != wordToGuess)
    {
        std::cout << "\nСлово: " << guessedWord << "\n";
        std::cout << "Оставшиеся попытки: " << attempts << "\n";
        std::cout << "Введите букву: ";

        char guess;
        std::cin >> guess;

        if (guessedLetters.find(guess) != std::string::npos)
        {
            std::cout << "Вы уже вводили эту букву!\n";
            continue;
        }

        guessedLetters += guess;
        bool correctGuess = false;

        for (int i = 0; i < wordLength; ++i)
        {
            if (wordToGuess[i] == guess)
            {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess)
        {
            attempts--;
            drawHangman(attempts);
        }
    }

    stopTimer();

    if (guessedWord == wordToGuess)
    {
        std::cout << "Поздравляем! Второй игрок угадал слово: " << wordToGuess << "\n";
    }
    else
    {
        std::cout << "Вы проиграли. Загаданное слово было: " << wordToGuess << "\n";
    }
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

// Рейтинг
void rating(int attempts, double elapsed_time, int correctGuesses, int incorrectGuesses)
{
    // Очки за правильные буквы
    int pointsForCorrectGuesses = correctGuesses * 10;

    // Штрафные очки за неправильные буквы
    int penaltyForIncorrectGuesses = incorrectGuesses * 5;

    // Очки за время (мы вычитаем очки за каждую секунду, если хотим усложнить задачу)
    int timePenalty = static_cast<int>(elapsed_time);  // Минусуем секунды из времени

    // Итоговые очки
    int totalPoints = pointsForCorrectGuesses - penaltyForIncorrectGuesses - timePenalty;

    // Печатаем результаты
    std::cout << "Рейтинг:\n";
    std::cout << "Правильные буквы: " << correctGuesses << " (+" << pointsForCorrectGuesses << " очков)\n";
    std::cout << "Неправильные буквы: " << incorrectGuesses << " (-" << penaltyForIncorrectGuesses << " очков)\n";
    std::cout << "Время: " << elapsed_time << " секунд (-" << timePenalty << " очков)\n";
    std::cout << "Итоговый счёт: " << totalPoints << " очков.\n";
}

// Основная логика игры
void playGame()
{
    chooseDifficulty();                 // Выбор сложности
    int language = chooseLanguage();    // Выбор языка
    const char* word = getRandomWord(language); // Получение случайного слова
    startTimer();  // Запуск таймера

    std::string wordToGuess(word);
    int wordLength = wordToGuess.length();
    std::string guessedWord(wordLength, '_');
    std::string guessedLetters;
    int attempts = 6;
    int correctGuesses = 0;  // Количество угаданных букв
    int incorrectGuesses = 0;  // Количество неправильных букв

    std::cout << "Загаданное слово (для теста): " << wordToGuess << "\n";
    std::cout << "Попробуйте угадать слово!\n";

    while (attempts > 0 && guessedWord != wordToGuess)
    {
        std::cout << "\nСлово: " << guessedWord << "\n";
        std::cout << "Оставшиеся попытки: " << attempts << "\n";
        std::cout << "Введите букву: ";

        char guess;
        std::cin >> guess;

        if (guessedLetters.find(guess) != std::string::npos)
        {
            std::cout << "Вы уже вводили эту букву!\n";
            continue;
        }

        guessedLetters += guess;
        bool correctGuess = false;

        for (int i = 0; i < wordLength; ++i)
        {
            if (wordToGuess[i] == guess)
            {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (correctGuess)
        {
            correctGuesses++;  // Увеличиваем счётчик правильных букв
        }
        else
        {
            incorrectGuesses++;  // Увеличиваем счётчик неправильных букв
            attempts--;
            drawHangman(attempts);
        }
    }

    stopTimer();  // Остановка таймера

    // Печать результатов игры
    if (guessedWord == wordToGuess)
    {
        std::cout << "Поздравляем! Вы угадали слово: " << wordToGuess << "\n";
    }
    else
    {
        std::cout << "Вы проиграли. Загаданное слово было: " << wordToGuess << "\n";
    }

    // Вызов функции для подсчёта рейтинга
    rating(attempts, std::difftime(stop_time, start_time), correctGuesses, incorrectGuesses);

}

// Основная функция
int main()
{
    setlocale(LC_ALL, "RUS");

    while (true)
    {
        showMenu();
        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            playGame();
        }
        else if (choice == 2)
        {
            multiplayerMode();
        }
        else if (choice == 3)
        {
            std::cout << "До свидания!\n";
            break;
        }
        else
        {
            std::cout << "Неверный выбор, попробуйте снова.\n";
        }
    }
}
