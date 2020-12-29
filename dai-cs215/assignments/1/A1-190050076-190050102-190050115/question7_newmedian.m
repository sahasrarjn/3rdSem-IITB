clear
function newMedian = UpdateMedian (oldMedian, NewDataValue, A, n) 
    if(rem(n,2) ==1)
        if(NewDataValue < oldMedian)
            newMedian = (A(fix(n/2))+A(fix(n/2)+1))/2;
        elseif(NewDataValue > oldMedian && NewDataValue < A(fix(n/2)+1))
            newMedian = (oldMedian + NewDataValue)/2;
        else
           newMedian = (A(fix(n/2)+1)+A(fix(n/2)+2))/2; 
        end
    else
        if(NewDataValue < A(fix(n/2)))
            newMedian = A(fix(n/2) + 1);
        elseif(NewDataValue > A(fix(n/2)) && NewDataValue < A(fix(n/2)+1))
            newMedian = NewDataValue;
        else
            newMedian = A(fix(n/2)+1);
        end
    end
end