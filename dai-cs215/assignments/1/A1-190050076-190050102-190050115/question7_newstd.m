clear
function newStd = UpdateStd (OldMean, OldStd, NewMean, NewDataValue, n)
    newStd = sqrt(((n-1)*OldStd^2 + ((OldMean-NewDataValue)/(n+1))^2 + (NewDataValue-NewMean)^2)/n);
end