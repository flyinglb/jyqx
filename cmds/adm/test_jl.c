int main(object me, string arg)
{
        //根据身法负重来消耗
        //"Amend_JingLi"
        int cost,i_jl;
        float f_jl;
        cost = (me->query_encumbrance()*100/me->query_max_encumbrance() ) - me->query_dex();
        if( cost < 10 ) cost = 10;//每次移动最底消耗 1/10 精力
        f_jl = me->query("Amend_JingLi") + to_float(cost) / 100;
        i_jl = f_jl;
        if( f_jl > 1.0000 ) {
                me->set("Amend_JingLi",f_jl - i_jl );
                me->add("jingli",- i_jl );
        } else {
                f_jl = to_float(cost)/100;
                me->add("Amend_JingLi",f_jl);
        }
        write("test cost:"+cost+"\n");
        write("test cost jingli:"+i_jl+"\n");
        write("test float jingli:"+f_jl+"\n");
        write("test :"+me->query("Amend_JingLi")+"\n");
        return 1;
}
