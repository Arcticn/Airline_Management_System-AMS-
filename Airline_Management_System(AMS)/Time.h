#pragma once

void SyncTime();
void RefreshLine();
bool operator<(const tm &lhs, const tm &rhs);
tm operator+(tm &lhs,int rhs);
int operator-(tm &lhs, tm &rhs);
