close all
clear all

raw = csvread ("ntc.csv")';
t1 = raw(1,:);
r = raw (2,:);

% figure
% plot(r, t1, '-')
% grid on
% hold on

ad=1024.*r./(r+10);

figure
plot(ad, t1, 'o')
grid on
hold on

p=polyfit(ad, t1, 10);
ad2 = 0:1023;
t2 = round(polyval(p, ad2), 1);
plot(ad2, t2, 'r');
dlmwrite('data.dlm', t2*10, ',');