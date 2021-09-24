function DataType = getDataTypeFromMaxAndSign(sign, digitLength, maxValue)
    if strcmp(sign,'s')
        signDigit = 1;
    else if strcmp(sign,'u')
        signDigit = 0;
        end
    end
    
    decimalDigit = digitLength - ( round(log2(maxValue)+0.5) + signDigit );
    
    DataType = fixdt(signDigit, digitLength, decimalDigit);
end