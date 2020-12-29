clear

figure(1)
x = [-3:0.02:3];
y = 5*sin(1.8*x + pi/3);
yorig = y;
size = numel(y);
plot(x,y,'color','c')
hold on
corrupted = fix(0.3*size);
r = randperm(size,corrupted);
y(r) = y(r) + 100 + (120 - 100)*rand(1,corrupted);

yquartile = zeros(1,size);
ymedian = zeros(1,size);
ymean = zeros(1,size);

for i=1:1:size
    if i<=8
       ymean(i) = mean(y(1:i+8));
    elseif i>=size-8
        ymean(i) = mean(y(i-8:size));
    else
        ymean(i) = mean(y(i-8:i+8));
    end
end

for i=1:1:size
    if i<=8
       ymedian(i) = median(y(1:i+8));
    elseif i>=size-8
        ymedian(i) = median(y(i-8:size));
    else
        ymedian(i) = median(y(i-8:i+8));
    end
end

for i=1:1:size
    if i<=8
       yquartile(i) = prctile(y(1:i+8),25);
    elseif i>=size-8
        yquartile(i) = prctile(y(i-8:size),25);
    else
        yquartile(i) = prctile(y(i-8:i+8),25);
    end
end

plot(x,y,'color','y')
plot(x,ymean,'color','g')
plot(x,ymedian,'color','b')
plot(x,yquartile,'color','m')
ylim([-20,140]);
lgd= legend('Original sine wave','Corrupted wave','moving mean filtered','moving median filtered','moving quartile filtered');
lgd.FontSize=6;
title('For 30% corruption')
hold off
fprintf("The errors for 30 percent corruption")
fprintf('\n')
fprintf("Error from mean filtering is \n")
error1  = sum((ymean - yorig).^2)/sum(yorig.^2)
fprintf("Error from median filtering is \n")
error2  = sum((ymedian - yorig).^2)/sum(yorig.^2)
fprintf("Error from quartile filtering is \n")
error3  = sum((yquartile - yorig).^2)/sum(yorig.^2)

fprintf("--------------------------------------------------------------")

figure(2)
x = [-3:0.02:3];
y = 5*sin(1.8*x + pi/3);
yorig = y;
size = numel(y);
plot(x,y,'color','c')
hold on
corrupted = fix(0.6*size);
r = randperm(size,corrupted);
y(r) = y(r) + 100 + (120 - 100)*rand(1,corrupted);

yquartile = zeros(1,size);
ymedian = zeros(1,size);
ymean = zeros(1,size);

for i=1:1:size
    if i<=8
       ymean(i) = mean(y(1:i+8));
    elseif i>=size-8
        ymean(i) = mean(y(i-8:size));
    else
        ymean(i) = mean(y(i-8:i+8));
    end
end

for i=1:1:size
    if i<=8
       ymedian(i) = median(y(1:i+8));
    elseif i>=size-8
        ymedian(i) = median(y(i-8:size));
    else
        ymedian(i) = median(y(i-8:i+8));
    end
end

for i=1:1:size
    if i<=8
       yquartile(i) = prctile(y(1:i+8),25);
    elseif i>=size-8
        yquartile(i) = prctile(y(i-8:size),25);
    else
        yquartile(i) = prctile(y(i-8:i+8),25);
    end
end

plot(x,y,'color','y')
plot(x,ymean,'color','g')
plot(x,ymedian,'color','b')
plot(x,yquartile,'color','m')
ylim([-20,140]);
lgd= legend('Original sine wave','Corrupted wave','moving mean filtered','moving median filtered','moving quartile filtered');
lgd.FontSize=6;
title('For 60 % corruption')
hold off
fprintf("The errors for 60 percent corruption")
fprintf("Error from mean filtering is \n")
error1  = sum((ymean - yorig).^2)/sum(yorig.^2)
fprintf("Error from median filtering is \n")
error2  = sum((ymedian - yorig).^2)/sum(yorig.^2)
fprintf("Error from quartile filtering is \n")
error3  = sum((yquartile - yorig).^2)/sum(yorig.^2)



