// main.cpp

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// расы
enum Race {
    HUMAN,
    ELF,
    ORC
};

//  классы
enum ClassType {
    WARRIOR,
    MAGE,
    ARCHER
};

// Базовый класс персонажа
class Character {
protected:
    string name;       // Имя персонажа
    Race race;         // Раса персонажа
    ClassType classType; // Класс персонажа
    int health;        // Здоровье
    int armor;         // Броня
    int attackPower;   // Сила атаки
    int agility;       // Ловкость
    int intelligence;  // Интеллект

public:
    // Конструктор для инициализации персонажа
    Character(string n, Race r, ClassType c) : name(n), race(r), classType(c) {
        // Инициализируем характеристики в зависимости от класса и расы
        initializeStats();
    }

    // Виртуальный деструктор
    virtual ~Character() {}

    // Инициализация характеристик
    void initializeStats() {
        // Базовые характеристики
        health = 100;
        armor = 10;
        attackPower = 15;
        agility = 10;
        intelligence = 10;

        // Модификаторы в зависимости от расы
        switch (race) {
            case HUMAN:
                health += 10;
                intelligence += 5;
                break;
            case ELF:
                agility += 10;
                intelligence += 5;
                break;
            case ORC:
                health += 20;
                attackPower += 5;
                break;
        }

        // Модификаторы в зависимости от класса
        switch (classType) {
            case WARRIOR:
                health += 20;
                armor += 10;
                attackPower += 5;
                break;
            case MAGE:
                intelligence += 15;
                attackPower -= 5;
                break;
            case ARCHER:
                agility += 15;
                attackPower += 5;
                break;
        }
    }

    //  имя персонажа
    string getName() const {
        return name;
    }

    // Проверка хп персонажа (жив/мертв)
    bool isAlive() const {
        return health > 0;
    }

    //  получение урона
    void takeDamage(int damage) {
        int effectiveDamage = damage - armor;
        if (effectiveDamage < 0) {
            effectiveDamage = 0;
        }
        health -= effectiveDamage;
        if (health < 0) {
            health = 0;
        }
        cout << name << " получил " << effectiveDamage << " урона. Осталось здоровья: " << health << endl;
    }

    // Виртуальные методы способностей
    virtual void ability1(Character* target) = 0;
    virtual void ability2(Character* target) = 0;
    virtual void ability3(Character* target) = 0;
    virtual void ability4(Character* target) = 0;

    // Выбор способности
    void useAbility(int abilityNumber, Character* target) {
        switch (abilityNumber) {
            case 1:
                ability1(target);
                break;
            case 2:
                ability2(target);
                break;
            case 3:
                ability3(target);
                break;
            case 4:
                ability4(target);
                break;
            default:
                cout << "Неверный номер способности!" << endl;
                break;
        }
    }

    // Функция для случайного хода
    void randomMove(Character* target) {
        int abilityNumber = rand() % 4 + 1; // Выбираем случайную способность от 1 до 4
        useAbility(abilityNumber, target);
    }
};

// Класс Воин
class Warrior : public Character {
public:
    Warrior(string n, Race r) : Character(n, r, WARRIOR) {}

    void ability1(Character* target) override {
        cout << name << " использует Сильный Удар на " << target->getName() << endl;
        target->takeDamage(attackPower + 10);
    }

    void ability2(Character* target) override {
        cout << name << " использует Защитную Стойку" << endl;
        armor += 5;
    }

    void ability3(Character* target) override {
        cout << name << " использует Рев Ярости" << endl;
        attackPower += 5;
    }

    void ability4(Character* target) override {
        cout << name << " использует Удар Щитом на " << target->getName() << endl;
        target->takeDamage(attackPower);
        target->takeDamage(5); // Дополнительный урон от щита
    }
};

// Класс Маг
class Mage : public Character {
public:
    Mage(string n, Race r) : Character(n, r, MAGE) {}

   
    void ability1(Character* target) override {
        cout << name << " использует Огненный Шар на " << target->getName() << endl;
        target->takeDamage(intelligence + 10);
    }

    void ability2(Character* target) override {
        cout << name << " использует Магический Щит" << endl;
        armor += 3;
    }

    void ability3(Character* target) override {
        cout << name << " использует Ледяной Луч на " << target->getName() << endl;
        target->takeDamage(intelligence);
    }

    void ability4(Character* target) override {
        cout << name << " использует Исцеление" << endl;
        health += 15;
        if (health > 100) health = 100;
        cout << name << " восстановил здоровье. Текущее здоровье: " << health << endl;
    }
};

// Класс Лучник
class Archer : public Character {
public:
    Archer(string n, Race r) : Character(n, r, ARCHER) {}


    void ability1(Character* target) override {
        cout << name << " использует Мощный Выстрел на " << target->getName() << endl;
        target->takeDamage(attackPower + 5);
    }

    void ability2(Character* target) override {
        cout << name << " использует Уклонение" << endl;
        agility += 5;
    }

    void ability3(Character* target) override {
        cout << name << " использует Двойной Выстрел на " << target->getName() << endl;
        target->takeDamage(attackPower);
        target->takeDamage(attackPower); // Двойная атака
    }

    void ability4(Character* target) override {
        cout << name << " использует Отравленную Стрелу на " << target->getName() << endl;
        target->takeDamage(attackPower);
        cout << target->getName() << " отравлен и получит дополнительный урон в следующий ход." << endl;
        
    }
};

// Функция для создания персонажа
Character* createCharacter() {
    string name;
    int raceChoice, classChoice;

    cout << "Введите имя персонажа: ";
    cin >> name;

    cout << "Выберите расу персонажа:" << endl;
    cout << "1 - Человек" << endl;
    cout << "2 - Эльф" << endl;
    cout << "3 - Орк" << endl;
    cout << "Ваш выбор: ";
    cin >> raceChoice;

    cout << "Выберите класс персонажа:" << endl;
    cout << "1 - Воин" << endl;
    cout << "2 - Маг" << endl;
    cout << "3 - Лучник" << endl;
    cout << "Ваш выбор: ";
    cin >> classChoice;

    Race race = static_cast<Race>(raceChoice - 1);
    ClassType classType = static_cast<ClassType>(classChoice - 1);

    switch (classType) {
        case WARRIOR:
            return new Warrior(name, race);
        case MAGE:
            return new Mage(name, race);
        case ARCHER:
            return new Archer(name, race);
        default:
            cout << "Неверный выбор класса." << endl;
            return nullptr;
    }
}

// Функция для управления ходом игрока
void playerTurn(Character* player, vector<Character*>& enemyTeam) {
    if (!player->isAlive()) {
        cout << player->getName() << " не может ходить, так как выбывший из строя." << endl;
        return;
    }

    cout << "Ходит " << player->getName() << endl;

    cout << "Выберите цель:" << endl;
    for (size_t i = 0; i < enemyTeam.size(); ++i) {
        if (enemyTeam[i]->isAlive()) {
            cout << i + 1 << " - " << enemyTeam[i]->getName() << endl;
        }
    }
    int targetIndex;
    cin >> targetIndex;
    Character* target = enemyTeam[targetIndex - 1];

    cout << "Выберите способность:" << endl;
    cout << "1 - Способность 1" << endl;
    cout << "2 - Способность 2" << endl;
    cout << "3 - Способность 3" << endl;
    cout << "4 - Способность 4" << endl;
    int abilityNumber;
    cin >> abilityNumber;

    player->useAbility(abilityNumber, target);
}

// Функция для автоматического хода персонажа
void autoTurn(Character* player, vector<Character*>& enemyTeam) {
    if (!player->isAlive()) {
        return;
    }

    // Выбираем случайную цель из живых врагов
    vector<Character*> aliveEnemies;
    for (Character* enemy : enemyTeam) {
        if (enemy->isAlive()) {
            aliveEnemies.push_back(enemy);
        }
    }
    if (aliveEnemies.empty()) {
        return;
    }
    Character* target = aliveEnemies[rand() % aliveEnemies.size()];

    // Совершаем случайный ход
    player->randomMove(target);
}

// все ли персонажи команды выбыли 
bool isTeamDefeated(const vector<Character*>& team) {
    for (Character* member : team) {
        if (member->isAlive()) {
            return false;
        }
    }
    return true;
}

// Функция для освобождения памяти команды
void cleanUpTeam(vector<Character*>& team) {
    for (Character* member : team) {
        delete member;
    }
    team.clear();
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    vector<Character*> team1;
    vector<Character*> team2;

    int teamSize;
    cout << "Введите количество персонажей в командах: ";
    cin >> teamSize;

    cout << "Формирование команды 1:" << endl;
    for (int i = 0; i < teamSize; ++i) {
        Character* character = createCharacter();
        if (character != nullptr) {
            team1.push_back(character);
        }
    }

    cout << "Формирование команды 2:" << endl;
    for (int i = 0; i < teamSize; ++i) {
        Character* character = createCharacter();
        if (character != nullptr) {
            team2.push_back(character);
        }
    }

    int gameMode;
    cout << "Выберите режим игры:" << endl;
    cout << "1 - Ручной режим" << endl;
    cout << "2 - Автоматический режим" << endl;
    cout << "Ваш выбор: ";
    cin >> gameMode;

    if (gameMode == 1) {
        // Ручной режим
        cout << "Начинается бой!" << endl;
        while (true) {
            // Ходы команды 1
            for (Character* player : team1) {
                if (isTeamDefeated(team2)) {
                    cout << "Команда 2 проиграла!" << endl;
                    cleanUpTeam(team1);
                    cleanUpTeam(team2);
                    return 0;
                }
                playerTurn(player, team2);
            }

            // Ходы команды 2
            for (Character* player : team2) {
                if (isTeamDefeated(team1)) {
                    cout << "Команда 1 проиграла!" << endl;
                    cleanUpTeam(team1);
                    cleanUpTeam(team2);
                    return 0;
                }
                playerTurn(player, team1);
            }
        }
    } else if (gameMode == 2) {
        // Автоматический режим с заранее заданными командами
        cout << "Автоматический бой начинается!" << endl;

        // Очищаем команды и создаем захардкоженные команды
        cleanUpTeam(team1);
        cleanUpTeam(team2);

        team1.push_back(new Warrior("Воин1", HUMAN));
        team1.push_back(new Mage("Маг1", ELF));
        team1.push_back(new Archer("Лучник1", ORC));

        team2.push_back(new Warrior("Воин2", ORC));
        team2.push_back(new Mage("Маг2", HUMAN));
        team2.push_back(new Archer("Лучник2", ELF));

        while (true) {
            // Ходы команды 1
            for (Character* player : team1) {
                if (isTeamDefeated(team2)) {
                    cout << "Команда 2 проиграла!" << endl;
                    cleanUpTeam(team1);
                    cleanUpTeam(team2);
                    return 0;
                }
                autoTurn(player, team2);
            }

            // Ходы команды 2
            for (Character* player : team2) {
                if (isTeamDefeated(team1)) {
                    cout << "Команда 1 проиграла!" << endl;
                    cleanUpTeam(team1);
                    cleanUpTeam(team2);
                    return 0;
                }
                autoTurn(player, team1);
            }
        }
    } else {
        cout << "Неверный выбор режима игры." << endl;
    }

    // Освобождаем память перед выходом
    cleanUpTeam(team1);
    cleanUpTeam(team2);

    return 0;
}
