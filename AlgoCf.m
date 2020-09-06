% WRITTEN BY: YIDA WANG
% January 27, 2020

clc
help AlgoCf

sizeMatrix = [10, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000];
optionA = [0.00000073, 0.00007174, 0.00028621, 0.00065525, 0.00117699, 0.00183620, 0.00261430, 0.00356440, 0.00461430, 0.00586840, 0.00723500];
optionB = [0.00000060, 0.00006284, 0.00025767, 0.00058274, 0.00102526, 0.00163310, 0.00232650, 0.00314670, 0.00408710, 0.00517000, 0.00633100];
figure(1);
hold on;
plot(sizeMatrix, optionA, 'r-', 'LineWidth',2);
plot(sizeMatrix, optionB, 'b-', 'LineWidth',2);
title('Code Option A vs Code Option B');
xlabel('Size of matrix');
ylabel('Execution time (seconds)');
grid minor;
p1 = polyfit(sizeMatrix, optionB, 2);
f1 = polyval(p1, sizeMatrix);
f1 = f1*1.055;
plot(sizeMatrix,f1,'--p', 'LineWidth',2);
legend('Option A', 'Option B', 'y = c f(x)');