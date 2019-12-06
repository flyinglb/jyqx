// location.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *place_desc = ({
        "�͵�" ,
        "����" ,
        "���Ĺ㳡" ,
        "��ʯ���" ,
        "ɽ·" ,
        "�����",
        "�ϴ��",
        "�����",
        "�����",
        "�����",
        "�ĳ�",
        "Ǯׯ",
        "����",
        "����"
});

int main(object me, string arg)
{
        object ob, *olist;
        mapping fam;
        int i, i1, cost;

        seteuid(getuid());

        if((time() - (int)me->query_temp("last_location_time") < 3)){
                write("�������Բ��Ǽ������������Ҫ��ʱ��ġ�\n");
                return 1;
        }

        if (me->is_busy() || me->is_fighting() )
                return notify_fail("��������æ���ء�\n");

//      if(environment(me)->query("no_fight") || environment(me)->query("no_magic") )
//              return notify_fail("��ȫ���ڲ������ˡ�\n");

        if ( (!(fam = me->query("family")) || fam["family_name"] != "�һ���") 
        && !wizardp(me) )
                return notify_fail("ֻ���һ������Ӳ��ܴ�̽���˵����ڣ�\n");

        if ( me->query_skill("count",1) < 10 )
                return notify_fail("�������������δ���죬�޷��˽���˵����ڣ�\n");

        if ( !arg )
                return notify_fail("��Ҫ����˭�����ڣ�\n");

        if ( present(arg, environment(me)) )
                return notify_fail("��Ҫ������˾��ڱ��ϣ���������ɣ�\n");
/*
        ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ����˭�����ڣ�\n");
        if (!me->visible(ob) ) return notify_fail("��Ҫ����˭�����ڣ�\n");
*/
        olist = livings();
        for(i=0,i1=sizeof(olist);i<i1;i++) {
                if( !olist[i]->id(arg) ) continue;
                if( !me->visible(olist[i]) ) continue;
                ob = olist[i];
                break;
        }
        if (!ob) return notify_fail("��Ҫ�Ʋ�˭�����ڣ�\n") ;
        if ( ob == me )
                return notify_fail("��û���᱿�ɣ�Ҫ���˸������Լ������ڣ�\n");

        cost = me->query("max_jing")/(me->query_skill("count",1)/10) - 10;

        if ( me->query("jing") <= cost )
                return notify_fail("������̫���ˣ��޷�ȥ������˵����ڡ�\n");
        
        message_vision("ֻ��$N��ϥ���£�˫�����գ����������дʡ���\n",me);
        i = 2+random(2);
//      me->start_busy(random(i-1));
        call_out("location_result",i,me,ob,arg,cost);
        me->receive_damage("jing", cost );
        me->set_temp("last_location_time",time());
        return 1;
}

void location_result(object me, object ob, string target, int cost)
{
        object where;
        int sp, dp;

        message_vision("��Ȼ$N��¶΢Ц: ����!\n",me);

        sp = me->query_skill("count",1)*10 + me->query("jing");
        dp = ob->query("kar")*5 + ob->query("jing")*2;
        
        if ( random(sp) < random(dp)/2 ) {
                tell_object(me,"������Ȼ���£�ҡ��ҡͷ��˵�������Եģ�\n");
                return;
        }


//      me->receive_damage("jing", cost );
        where = environment(ob);
        if(!where) {
                tell_object(me,"����˲�֪��������Ү...\n");
                return;
        }
        if ( random(sp) < random(dp) ) 
        {
                if (strsrch(file_name(where), "baituo") >= 0)
                        tell_object(me, ob->name()+"�����ڰ���ɽ��\n");
                if (strsrch(file_name(where), "bupingshe") >= 0)
                        tell_object(me, ob->name()+"�����ڲ�ƽ�磡\n");
                if (strsrch(file_name(where), "city4") >= 0)
                        tell_object(me, ob->name()+"�����ڳ����ǣ�\n");
                if (strsrch(file_name(where), "city3") >= 0)
                        tell_object(me, ob->name()+"�����ڳɶ��ǣ�\n");
                if (strsrch(file_name(where), "city2") >= 0)
                        tell_object(me, ob->name()+"�����ڱ����ǣ�\n");
                if (strsrch(file_name(where), "city") >= 0)
                        tell_object(me, ob->name()+"���������ݳǣ�\n");
                if (strsrch(file_name(where), "dali") >= 0)
                        tell_object(me, ob->name()+"�����ڴ���ǣ�\n");
                if (strsrch(file_name(where), "death") >= 0)
                        tell_object(me, ob->name()+"�����ڵ����\n");
                if (strsrch(file_name(where), "emei") >= 0)
                        tell_object(me, ob->name()+"�����ڶ�üɽ�ϣ�\n");
                if (strsrch(file_name(where), "gaochang") >= 0)
                        tell_object(me, ob->name()+"�����ڸ߲��Թ���\n");
                if (strsrch(file_name(where), "gumu") >= 0)
                        tell_object(me, ob->name()+"�����ڻ�����Ĺ��\n");
                if (strsrch(file_name(where), "guiyun") >= 0)
                        tell_object(me, ob->name()+"�����ڹ���ׯ��\n");
                if (strsrch(file_name(where), "wudujiao") >= 0)
                        tell_object(me, ob->name()+"�������置��\n");
                if (strsrch(file_name(where), "foshan") >= 0)
                        tell_object(me, ob->name()+"�����ڷ�ɽ��\n");
                if (strsrch(file_name(where), "fuzhou") >= 0)
                        tell_object(me, ob->name()+"�����ڸ��ݳǣ�\n");
                if (strsrch(file_name(where), "gaibang") >= 0)
                        tell_object(me, ob->name()+"������ؤ���\n");
                if (strsrch(file_name(where), "guanwai") >= 0)
                        tell_object(me, ob->name()+"�����ڹ��⣡\n");
                if (strsrch(file_name(where), "hangzhou") >= 0)
                        tell_object(me, ob->name()+"�����ں��ݳǣ�\n");
                if (strsrch(file_name(where), "heishou") >= 0)
                        tell_object(me, ob->name()+"��������ָɽׯ��\n");
                if (strsrch(file_name(where), "heimuya") >= 0)
                        tell_object(me, ob->name()+"�����ں�ľ���ϣ�\n");
                if (strsrch(file_name(where), "hengshan") >= 0)
                        tell_object(me, ob->name()+"�����ں�ɽ�ϣ�\n");
                if (strsrch(file_name(where), "henshan") >= 0)
                        tell_object(me, ob->name()+"�����ں�ɽ�ϣ�\n");
                if (strsrch(file_name(where), "henshan") >= 0)
                        tell_object(me, ob->name()+"�����ں�ɽ�ϣ�\n");
                if (strsrch(file_name(where), "huanggon") >= 0)
                        tell_object(me, ob->name()+"�����ڻʹ������\n");
                if (strsrch(file_name(where), "huashan") >= 0)
                        tell_object(me, ob->name()+"�����ڻ�ɽ�ϣ�\n");
                if (strsrch(file_name(where), "jinshe") >= 0)
                        tell_object(me, ob->name()+"�����ڽ��߶���\n");
                if (strsrch(file_name(where), "kunlun") >= 0)
                        tell_object(me, ob->name()+"����������ɽ�ϣ�\n");
                if (strsrch(file_name(where), "lingjiu") >= 0)
                        tell_object(me, ob->name()+"���������շ��ϣ�\n");
                if (strsrch(file_name(where), "lingxiao") >= 0)
                        tell_object(me, ob->name()+"�����������ǣ�\n");
                if (strsrch(file_name(where), "lingzhou") >= 0)
                        tell_object(me, ob->name()+"���������ݳǣ�\n");
                if (strsrch(file_name(where), "meizhuang") >= 0)
                        tell_object(me, ob->name()+"������÷ׯ��\n");
                if (strsrch(file_name(where), "mingjiao") >= 0)
                        tell_object(me, ob->name()+"����������ɽ�ϣ�\n");
                if (strsrch(file_name(where), "murong") >= 0)
                        tell_object(me, ob->name()+"�����������룡\n");
                if (strsrch(file_name(where), "piaoxue") >= 0)
                        tell_object(me, ob->name()+"������Ʈѩɽׯ��\n");
                if (strsrch(file_name(where), "players") >= 0)
                        tell_object(me, ob->name()+"�����������ˣ�\n");
                if (strsrch(file_name(where), "qixinglou") >= 0)
                        tell_object(me, ob->name()+"����������¥��\n");
                if (strsrch(file_name(where), "qingcheng") >= 0)
                        tell_object(me, ob->name()+"���������ɽ�ϣ�\n");
                if (strsrch(file_name(where), "quanzhen") >= 0)
                        tell_object(me, ob->name()+"����������ɽ�ϣ�\n");
                if (strsrch(file_name(where), "quanzhou") >= 0)
                        tell_object(me, ob->name()+"������Ȫ�ݳǣ�\n");
                if (strsrch(file_name(where), "shaolin") >= 0)
                        tell_object(me, ob->name()+"�������������\n");
                if (strsrch(file_name(where), "shenlong") >= 0)
                        tell_object(me, ob->name()+"�������������ϣ�\n");
                if (strsrch(file_name(where), "songshan") >= 0)
                        tell_object(me, ob->name()+"��������ɽ�ϣ�\n");
                if (strsrch(file_name(where), "suzhou") >= 0)
                        tell_object(me, ob->name()+"���������ݳǣ�\n");
                if (strsrch(file_name(where), "taishan") >= 0)
                        tell_object(me, ob->name()+"������̩ɽ�ϣ�\n");
                if (strsrch(file_name(where), "tiezhang") >= 0)
                        tell_object(me, ob->name()+"����������ɽ�ϣ�\n");
                if (strsrch(file_name(where), "taohua") >= 0)
                        tell_object(me, ob->name()+"�������һ�����\n");
                if (strsrch(file_name(where), "taohuacun") >= 0)
                        tell_object(me, ob->name()+"�������һ��壡\n");
                if (strsrch(file_name(where), "tianjian") >= 0)
                        tell_object(me, ob->name()+"�������콣�ţ�\n");
                if (strsrch(file_name(where), "tianlongsi") >= 0)
                        tell_object(me, ob->name()+"�������������\n");
                if (strsrch(file_name(where), "village") >= 0)
                        tell_object(me, ob->name()+"�����ڻ�ɽ�壡\n");
                if (strsrch(file_name(where), "wizard") >= 0)
                        tell_object(me, ob->name()+"�������ɽ磡\n");
                if (strsrch(file_name(where), "wanjiegu") >= 0)
                        tell_object(me, ob->name()+"��������ٹȣ�\n");
                if (strsrch(file_name(where), "wudang") >= 0)
                        tell_object(me, ob->name()+"�������䵱ɽ�ϣ�\n");
                if (strsrch(file_name(where), "xiakedao") >= 0)
                        tell_object(me, ob->name()+"���������͵��ϣ�\n");
                if (strsrch(file_name(where), "xiaoyao") >= 0)
                        tell_object(me, ob->name()+"��������ң���\n");
                if (strsrch(file_name(where), "xingxiu") >= 0)
                        tell_object(me, ob->name()+"���������޺���\n");
                if ((strsrch(file_name(where), "xuedao") >= 0) ||
                   (strsrch(file_name(where), "xueshan") >= 0))
                        tell_object(me, ob->name()+"�����ڴ�ѩɽ�ϣ�\n");
                if (strsrch(file_name(where), "xiangyang") >= 0)
                        tell_object(me, ob->name()+"�����������ǣ�\n");
                else tell_object(me, ob->name()+"�����������أ���֪������\n");
                return;
        }
        if (random(10)>7)
        {
                printf("%s������%s��\n",
                (string)ob->name(), place_desc[random(sizeof(place_desc))]);
                return ;
        }
        printf("%s������%s��\n",
                (string)ob->name(),
                (string)where->query("short"));
        return ;
}


int help(object me)
{
        write(@HELP
ָ���ʽ: location <��ҵ� ID>

���ָ�����һ�������������֪���Ŀǰ���ڵ�λ�á�

HELP
        );
        return 1;
}


