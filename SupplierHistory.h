
#ifndef TPCUATRIMESTRAL_SUPPLIERHISTORY_H
#define TPCUATRIMESTRAL_SUPPLIERHISTORY_H

#include "PaymentReceipt.h"

typedef struct SupplierHistory {
    PaymentReceipt** receipts;
    int maxReceipts;
    int currentReceipts;
    int id;
} SupplierHistory;

SupplierHistory* createSupplierHistory(int id);
void addReceipt(PaymentReceipt*, SupplierHistory* supplierHistory);
int getSupplierHistoryID(SupplierHistory* supplie);

#endif //TPCUATRIMESTRAL_SUPPLIERHISTORY_H
