constexpr long long clickUpgradesBaseCost[] = { 25, 7500, 85500 };
constexpr long long   cpsUpgradesBaseCost[] = { 10, 2500, 12500 };
constexpr long long clickUpgrades[] = { 1, 10, 50 };
constexpr long long   cpsUpgrades[] = { 1, 8 , 23 };

constexpr double coef = 2.63;
const QString greenButtonStyle = "QPushButton{ \
    color: white; \
    background-color: rgba(0, 255, 85, 70); \
    border: none; \
    font-size: 27pt; \
} \
    QPushButton:hover{ \
        background-color: rgba(25, 255, 100, 85); \
} \
    QPushButton:pressed{ \
        background-color: rgba(0, 255, 0, 65); \
}";
    const QString redButtonStyle = "QPushButton{\
    color: white;\
    background-color: rgba(255, 80, 100, 60);\
    border: none;\
    font-size: 27pt;\
}\
    QPushButton:hover{\
        background-color: rgba(255, 80, 100, 75);\
}\
    QPushButton:pressed{\
        background-color: rgba(255, 80, 100, 90);\
}";
