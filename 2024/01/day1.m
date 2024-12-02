t = readtable("input.txt");
len = height(t);

tot = 0;
similarity_score = 0;

for i = 1:len   
    v = t.Var1(i);
    similarity_score = similarity_score + v * length(find(t.Var2==v));
end


for i = 1:len
    [v1,i1] = min(t.Var1);
    [v2,i2] = min(t.Var2);

    tot = tot + abs(v1-v2);

    t.Var1(i1) = inf;
    t.Var2(i2) = inf;
end

tot
similarity_score
