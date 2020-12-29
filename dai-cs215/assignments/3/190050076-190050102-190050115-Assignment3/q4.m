
S = 4*randn(1,1000);   % 1000 random samples from normal random variable with mean 0 and variance 16.
T = S(1:750);
V = S(751:1000);
                        %assigning T and V in this manner ensures that both
                        %of them are disjoint.
V = reshape(V,[length(V),1]); 

sigmas = [0.001, 0.1, 0.2, 0.9, 1, 2, 3, 5, 10, 20, 100];
log_s = log(sigmas);
n = 750;
LL = [];     %log likelihood vector.

for sig = [0.001, 0.1, 0.2, 0.9, 1, 2, 3, 5, 10, 20, 100]
    est = sum(exp(-(V - T).^2./(2*sig^2))./(n*sig*sqrt(2*pi)),2);
    LL = [LL sum(log(est))];
end

[M i] = max(LL);            %finding the index for which LL is max.
best_sig = sigmas(i)        %sigma w.r.t. that index. (best sigma)
figure();
plot(log_s,LL);             %log(sigma) vs LL plot.
xlabel("log(\sigma)")
ylabel("log likelihood (LL)")
title("log(\sigma) vs log likelihood(LL)")
%-----pdf for best sigma------

x = -8:0.1:8;
x = reshape(x,[length(x),1]);
y = sum(exp(-(x-T).^2./(2*best_sig^2))/(n*best_sig*sqrt(2*pi)),2);
y = reshape(y,[1,length(y)]);   

y1 = exp(-(x.^2)./(2*16))/(4*sqrt(2*pi));       %true pdf.
figure();
plot(x,y,x,y1);
xlabel("x");
ylabel("pdf $\hat{p}(x;\sigma)$",'Interpreter','latex')
legend('estimated pdf','true pdf')
title("Estimated and true pdf (Cross Validation)")


%=============Question 4 (d) PART================

D = [];      % D is as mentioned in the questions.
for sig = [0.001, 0.1, 0.2, 0.9, 1, 2, 3, 5, 10, 20, 100]

    est = sum(exp(-(V - T).^2./(2*sig^2))./(n*sig*sqrt(2*pi)),2);
    real = exp(-(V.^2)./(2*16))/(4*sqrt(2*pi));
    
    D = [D sum((real - est).^2)];
end
[m j] = min(D);      %finding index for which D is minimum.

best_sig1 = sigmas(j)       %sigma corresponding to minimum D (best sigma)
minD = D(j)
D_CV = D(i)              %D corresponding to best sigma in c part. (CV)
figure()
plot(log_s,D);      %log(sigma) vs D plot.
xlabel("log(\sigma)")
ylabel("D")
title("D vs log(\sigma)")


%-----------pdf for best sigma--------
x = -8:0.1:8;
x = reshape(x,[length(x),1]);
y2 = sum(exp(-(x-T).^2./(2*best_sig1^2))/(n*best_sig1*sqrt(2*pi)),2);
y2 = reshape(y,[1,length(y)]);

figure();
plot(x,y2,x,y1);
xlabel("x");
ylabel("pdf $\hat{p}(x;\sigma)$",'Interpreter','latex')
legend('estimated pdf','true pdf')
title("Estimated and true pdf (Method in part (d))")

