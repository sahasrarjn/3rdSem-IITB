
I1 = imread('T1.jpg');

[rows, cols] = size(I1);

pixels = rows*cols;

r = zeros(21,1);
qmi = zeros(21,1);


for i = -10:1:10
    I2 = imread('T2.jpg');
    
    I2 = circshift(I2, i, 2);
    
    if i < 0
        I2(:, size(I2,2)+i+1:size(I2,2)) = 0;
    end
    
    if i > 0
        I2(:, 1:i) = 0;
    end

    imshow(I2)
    
    
    coeff = corrcoef(double(I1(:)),double(I2(:)));
   
    r(i+11) = coeff(1,2); 
    
    p = zeros(26,1);
    p2 = zeros(26,1);
    joint = zeros(26,26);

    for j = 1:rows
        for k = 1:cols
            x = double(I1(j,k));
            x2 = double(I2(j,k));
            x = floor(x/10) + 1;
            x2 = floor(x2/10) + 1;
            
            joint(x, x2) = joint(x,x2) + 1;
        end
    end
    
    p2 = sum(joint);
    
    p = sum(joint, 2);
    p = p';
    
    
    p = p ./ pixels;
    p2 = p2 ./ pixels;
    joint = joint ./ sum(joint(:));
    
    for j = 1:26        
        for k = 1:26
            qmi(i+11) = qmi(i+11) + (joint(j,k) - p(j)*p2(k))^2;
        end
    end
    
    
end

plot(-10:1:10, r.')
title('Correlation Coefficient vs t_x')
xlabel('t_x')
ylabel('Correlation ')
saveas(gcf,'CorrelationCoeff.png')

plot(-10:1:10, qmi.')
title('Quadratic Mean Information(QMI) vs t_x')
xlabel('t_x')
ylabel('Quadratic Mean Infromation (QMI)')
saveas(gcf,'QMI.png')