if exist('s', 'var') && s.status(1) == 'o'
for m = 1:1:size(naszekroki,1)
    
    %str = sprintf('x %d y %d z %d\n', naszekroki(m,1), naszekroki(m,2), naszekroki(m,3));
    str = ['x ' num2str(naszekroki(m,1)) ' y ' num2str(naszekroki(m,2)) ' z ' num2str(naszekroki(m,3)) '\n'];
    fprintf(s, '%s', str);
    pause(0.15);
end
end
