N = [5, 10, 20, 50, 100, 200, 500, 1000, 5000, 10000];
madgraph = zeros(1,10);
for i=1:10
    madgraph(i) = histplt(N(i));
end
figure()
plot(N,madgraph);
xlabel("N");
ylabel("MAD");
grid on
title("MAD between E^{(N)}(x) and \phi^{(N)}(x) v/s N")

%--------------------------------to plot the histogram for a particular N
% uncomment the below line and the lines commented in the function and
% comment the lines above this-------------------------------------------

% k = histplt(100);
% k1 = histplt(1000);
% k2 = histplt(10000);

function MAD = histplt(n)
    y = zeros(1,2000);
    for iter =1:2000
        x = zeros(1,n);
        for i = 1:n
            k = rand();
            if k<0.05
                x(i) = 1;
            elseif k <0.45
                x(i) = 2;
            elseif k < 0.6
                x(i) = 3;
            elseif k<0.9
                x(i) = 4;
            else
                x(i) = 5;
            end
        end
        y(iter)=mean(x);
    end
    figure()
    histogram(y,50)
    ylabel("Frequency")
    xlabel("X_{avg}^N")
    title(sprintf("Histogram for N = %d",n))
    
    gmean = 3;
    gstd = sqrt(1.3/n);
    [f,xx] = ecdf(y);
    g = normcdf(xx,gmean,gstd);
    
    figure()
    plot(xx,f);
    grid on
    hold on
    plot(xx,g);
    xlabel("x")
    ylabel("Cumulative probability")
    legend("E^{(N)}(x)","\phi^{(N)}(x)")
    title(sprintf("CDF plots for N = %d",n))
    hold off
    MAD = max(abs(g-f));
end
