#pragma once

void SyncTime();
void SyncDate();
bool operator<(const tm &lhs, const tm &rhs);
tm &operator+=(const tm &lhs,int rhs);
int operator-(tm &lhs, tm &rhs);
