clear;
x11 = 0;
y11 = 1;
z11 = 0;
x12 = 0;
y12 = 1;
z12 = 4;
x21 = 0;
y21 = 3;
z21 = 0;
x22 = 0;
y22 = 3;
z22 = 4;
x31 = 1.7;
y31 = 2;
z31 = 0;
x32 = 1.7;
y32 = 2;
z32 = 4;
xc = 0.6;
yc = 2.4;
zc = 2;
r=2;
mojei = 1;
mojej = 1;
naszekroki = zeros(201,3);
col1 = line([x11 x11],[y11 y11], [z11 z12]);
col2 = line([x21 x21],[y21 y21], [z21 z22]);
col3 = line([x31 x31],[y31 y31], [z31 z32]);
zcostam1=zc + power(r*r -(x11-xc)*(x11-xc) - (y11-yc)*(y11-yc),1/2);
zcostam2=zc + power(r*r -(x21-xc)*(x21-xc) - (y21-yc)*(y21-yc),1/2);
zcostam3=zc + power(r*r -(x31-xc)*(x31-xc) - (y31-yc)*(y31-yc),1/2);
arm1 = line([xc x11],[yc y11], [zc zcostam1]);
arm2 = line([xc x21],[yc y21], [zc zcostam2]);
arm3 = line([xc x31],[yc y31], [zc zcostam3]);
hold on
for t=0:0.1:20
    xc = 0.6 +0.5*sin(t);
    yc = 2.4 +0.3*cos(t);
    zc = 2-t/20;
    
    zcostam1=zc + power(r*r -(x11-xc)*(x11-xc) - (y11-yc)*(y11-yc),1/2);
    zkrok1=zcostam1;
    naszekroki(mojei,mojej) = zkrok1;
    mojej = mojej + 1;
    zcostam2=zc + power(r*r -(x21-xc)*(x21-xc) - (y21-yc)*(y21-yc),1/2);
    zkrok2=zcostam2;
    naszekroki(mojei,mojej) = zkrok2;
    mojej = mojej + 1;
    zcostam3=zc + power(r*r -(x31-xc)*(x31-xc) - (y31-yc)*(y31-yc),1/2);
    zkrok3=zcostam3;
    naszekroki(mojei,mojej) = zkrok3;
    mojej = 1;
    set(arm1,'XData',[xc x11],'YData',[yc y11],'ZData',[zc zcostam1]);
    set(arm2,'XData',[xc x21],'YData',[yc y21],'ZData',[zc zcostam2]);
    set(arm3,'XData',[xc x31],'YData',[yc y31],'ZData',[zc zcostam3]);
    mojei = mojei + 1;
%     plot3(xc,yc,zc,'.')
%     pause(0.1)
end


naszekroki2 = zeros(200,3);
for j = 1:1:200
    for k = 1:1:3
        naszekroki2(j,k)=naszekroki(j+1,k)*5000-naszekroki(j,k)*5000;
    end
end

naszekroki3 = naszekroki;
for j = 1:1:201
    for k = 1:1:3
        if j == 1
            naszekroki(j,k) = (4 - naszekroki(j,k));
        else
            naszekroki(j,k) = (naszekroki3(j-1,k)- naszekroki(j,k));
        end
    end
end
naszekroki = -(naszekroki * 5000);
naszekroki = ceil(naszekroki);
naszekroki2 = ceil(naszekroki2);
naszekroki(1,1) = -5000;
naszekroki(1,2) = -5000;
naszekroki(1,3) = -5000;

if ~exist('s','var')
    s = serial('/dev/ttyUSB1', 'BaudRate', 9600);
    %set(s,'BaudRate', 9600);
end
if s.status(1)=='c'
fopen(s);
pause(2);
end
% for m = 1:1:size(naszekroki,1)
%     
%     %str = sprintf('x %d y %d z %d\n', naszekroki(m,1), naszekroki(m,2), naszekroki(m,3));
%     str = ['x ' num2str(naszekroki(m,1)) ' y ' num2str(naszekroki(m,2)) ' z ' num2str(naszekroki(m,3)) '\n'];
%     fprintf(s,str);
%     disp(m);
%     pause(0.8);
% end
% if s.status(1)=='c'
% fopen(s);
% pause(0.5);
% end
% str=sprintf('x 500 y 500 z 500 \n');
% fprintf(s,str);
% pause(0.5);
% fclose(s);
