cmake_minimum_required(VERSION 3.5)
project(Implementaciones)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES
    Address.c
    Address.h
    Bill.c
    Bill.h
    CreditCard.c
    CreditCard.h
    Deposit.c
    Deposit.h
    Payment.c
    Payment.h
    PaymentReceipt.c
    PaymentReceipt.h
    Person.c
    Person.h
    PersonTechSupport.c
    PersonTechSupport.h
    Product.c
    Product.h
    Question.c
    Question.h
    Shipping.c
    Shipping.h
    ShoppingCart.c
    ShoppingCart.h
    Supplier.c
    Supplier.h
    SupplierHistory.c
    SupplierHistory.h
    TechSupport.c
    TechSupport.h
    TransactionHistory.c
    TransactionHistory.h
    Transfer.c
    Transfer.h
    User.c
    User.h main.c Contract.c Contract.c Contract.h)

add_executable(Implementaciones ${SOURCE_FILES})