test_pass=[]
res=[]

test1=0
exec loader.sce
/////////Test case for       2) arburg                  //////////

a = octave_fun([1,2,3,4,5],[2],[],"arburg","signal");
a = round(a*10000)/10000;

if(a == [1.  -1.8639    0.9571])
    test_pass=[test_pass,1]
else
    test_pass=[test_pass,0]
    disp("arburg test failed")
end

/////////Test case for       4) aryule                  //////////

a = octave_fun([1,2,3,4,5],[2],[],"aryule","signal");
a = round(a*10000)/10000;

if(a == [1.  -0.814    0.1193])
    test_pass=[test_pass,1]
else
    test_pass=[test_pass,0]
    disp("aryule test failed")
end

/////////Test case for       38)levinson                  //////////

a = [1 0.1 -0.8];
v = 0.4;
rand("seed", 0);
w = sqrt(v)*rand(15000,1);
x=octave_fun(1,a,w,"filter","signal");

r=octave_fun(x,[],[],"xcorr","signal");

ar=octave_fun(r,length(a)-1,[],"levinson","signal");

ar = round(ar*10000)/10000

if(ar == [1 0.0984 -0.793])
           test_pass=[test_pass,1]
    else
	test_pass=[test_pass,0]
	disp("levinson Test failed")
end

/////////Test case for       **)sigmoid_train                  //////////

s = octave_fun(0.1,[1:3],[4],"sigmoid_train");
s = round(s*10000)/10000

if(s == 0.2737)
           test_pass=[test_pass,1]
else
	test_pass=[test_pass,0]
	disp("sigmoid_train Test failed")
end

/////////Test case for       **)circshift                  /////////

 M = [1 2 3 4];
 R = octave_fun(M,[0 1],[],"circshift")

if(R == [4 1 2 3])
           test_pass=[test_pass,1]
else
	test_pass=[test_pass,0]
	disp("circshift failed")
end

/////////////////////////////////////////////
/////////Test case for       **)kaiser                 //////////

win = octave_fun(6,[0.2],[],"kaiser") ;
win = round(win*10000)/10000;

if(win == [ 0.9901; 0.9964; 0.9996; 0.9996; 0.9964; 0.9901 ])
           test_pass=[test_pass,1]
else
	test_pass=[test_pass,0]
	disp("kaiser Test failed")
end

/////////////////////////////////////////////

/////////////////////////////////////////////


/////////Test case for       autoreg_matrix                 //////////
m = octave_fun([1 2 3],[2],[],"autoreg_matrix")

if(m == [1 0 0; 1 1 0; 1 2 1])
           test_pass=[test_pass,1]
else
	test_pass=[test_pass,0]
	disp("autoreg_matrix test failed")
end

/////////////////////////////////////////////
/////////Test case for       arch_rnd                 //////////

a = [1 2 3 4 5];
b = [7 8 9 10];
t = 5 ;
rand("seed", 0)
m = octave_fun(a,b,t,"arch_rnd");
m = round(m*1000)/1000

if(m == [ 7.211
    65.48
    654.008
    7194.657
    78364.905 ])
           test_pass=[test_pass,1]
else
	test_pass=[test_pass,0]
	disp("arch_rnd Test failed")
end

/////////////////////////////////////////////

/////////Test case for       postpad                 //////////

y = octave_fun([1 2 3],6,[],"postpad");

if(y == [1 2 3 0 0 0 ] )
           test_pass=[test_pass,1]
else
	test_pass=[test_pass,0]
	disp("postpad Test failed")
end


/////////Test case for       wconv                 //////////
a = [1 2 3 4 5];
b = [7 8 9 10];
y = octave_fun([1],a,b,"wconv");

if(y == [7.    22.    46.    80.    114.    106.    85.   50.])
           test_pass=[test_pass,1]
else
	test_pass=[test_pass,0]
	disp("wconv Test failed")
end
/////////Test case for       dctmtx                 //////////
T = octave_fun([3],[],[],"dctmtx");
T = round(T*10000)/10000;
if(T == [0.5774  0.5774  0.5774; 0.7071  0  -0.7071; 0.4082 -0.8165 0.4082])
           test_pass=[test_pass,1]
else
	test_pass=[test_pass,0]
	disp("dctmtx Test failed")
end

/////////////////////////////////////////////
res=find(test_pass==0)

if(res~=[])
    disp("One or more tests failed in test1")
    disp(length(test_pass),"Total functions tested in test1:")
    test1=1;
end
