// go.c
// Modified by Eatdami@MX (10/16/2000)

inherit F_CLEAN_UP;

mapping default_dirs = ([
        "north":        "��",
        "south":        "��",
        "east":         "��",
        "west":         "��",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "��",
        "down":         "��",
        "out":          "��",
        "enter":        "��",
]);

void create() { seteuid(getuid()); }

//add Byp@MX 
void consume_jingli(object me)
{
        //����������������
        int cost,i_jl;
        float f_jl;
        
        
        if( !userp(me) ) return;
        cost = (me->query_encumbrance()*100/me->query_max_encumbrance() ) - me->query_dex();
        if( cost < 10 ) cost = 10;//ÿ���ƶ�������� 1/10 ����
        f_jl = me->query("Amend_JingLi") + to_float(cost) / 100;
        i_jl = f_jl;//����֣�driver �� to_int ת����ʱ�������Щ����
        if( f_jl > 1.0000 ) {
                me->set("Amend_JingLi",f_jl - i_jl );
                me->add("jingli",- i_jl );
        } else {
                f_jl = to_float(cost)/100;
                me->add("Amend_JingLi",f_jl);
        }
}

int main(object me, string arg)
{
	string dest, mout, min, dir, msg;
        object env, obj;
        int mq,eq;
        mapping exit;
        object *f_obs,*ob;
        int count = 0, my_dex, i;

        mq=(int)me->query("max_qi");
        eq=(int)me->query("eff_qi");
        if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

        if( userp(me) && me->over_encumbranced() )
                return notify_fail("��ĸ��ɹ��أ��������á�\n");

        if( me->is_busy() )
                return notify_fail("��Ķ�����û����ɣ������ƶ���\n");

        if( userp(me) && me->query("jingli") < 1 )//add Byp@MX 
                return notify_fail("�������ۼ��ˣ��޷����ƶ��벽��\n");

        if (me->is_fighting()) {
                f_obs = me->query_enemy();
                if (objectp(f_obs[0]))
                if (5 + random((int)me->query("dex")) <=
                       random((int)f_obs[0]->query("dex"))) {
                        me->start_busy(1);
                        message_vision("$N���Ʋ��ã�ת��Ҫ�ߣ���$nһ��������ǰ�����ߣ�û��ô���ף�\n", me, f_obs[0]);
                        return notify_fail("������ʧ�ܡ�\n");
                }
        }

        env = environment(me);
        if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                if( query_verb()=="go")
                        return notify_fail("�������û�г�·��\n");
//                        return notify_fail("�ˣ���һ����е�ͷ��Ŀѣ�ƺ�ײ��ʲôӲ������\n�㷢���������û�г�·��\n");
                else
                        return 0;
        }

        dest = exit[arg];

        if( !(obj = load_object(dest)) )
                return notify_fail("�޷��ƶ���\n");

        ob = all_inventory(obj);
        for(i=0; i<sizeof(ob); i++)
                if( living(ob[i]) && ob[i] != me )
                        count++;
        my_dex = (int)me->query_dex();

/*
        if(!obj->is_chatting_room()
        && (((my_dex < 15) && (count > 6))
        || ((my_dex < 20) && (count > 8))
        || ((my_dex < 30) && (count > 10))
        || ((my_dex < 35) && (count > 12))
        || ((my_dex < 40) && (count > 16))
        || ((my_dex < 45) && (count > 20))
        || (count > 30)))
*/
        if( !obj->is_chatting_room() && count > my_dex / 3 * 10)
                return notify_fail("ǰ����̫���ˣ�����ô��Ҳ������ȥ��\n");
        if( !env->valid_leave(me, arg) ) return 0;

        if( !undefinedp(default_dirs[arg]) )
                dir = default_dirs[arg];
        else
                dir = arg;

        if( me->is_fighting() ) {
                mout = "��" + dir + "��Ķ����ˡ�\n";
                min = "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
             }
	else
        if(100*eq/mq<=30 ){
        mout = RED"��ס�����������ű������˵Ĳ�����" + dir + "��ȥ�����Ϻ�Ȼ����һ�����߰ߵ�Ѫ����\n"NOR;
        min = RED"��ס�����������ű������˵Ĳ������˹�����\n"NOR;
        } else
        if(100*eq/mq<=50 ){
        mout = RED"����������Ѫ�����壬һȳһ�յس�" + dir + "Ųȥ��\n"NOR;
        min =RED"����������Ѫ�����壬һȳһ�յ�Ų�˹�����\n"NOR;
        } else
        if(100*eq/mq<=70){
        mout = HIC"һ�߲�����ǵ���Ѫ��һ�߳�" +dir+"��ȥ��\n"NOR;
        min = HIC"һ�߲�����ǵ���Ѫ��һ�����˹�������������ġ�\n"NOR;
        } else
        if(100*eq/mq<=90 ){
        mout = WHT"��ͷ�������Ǳ���������"+dir+"��ȥ��\n"NOR;
        min = WHT"��ͷ�������Ǳ����������˹�����\n"NOR;
        } else
        if(100*eq/mq<=95){
        mout = CYN"�����򶨵�ת��"+dir+"��ȥ��ƨ���Ϻ�Ȼһ����ӡ��\n"NOR;
        min = CYN"�����򶨵����˹�����ȫȻ��֪�ղŵ���һ�ŵ�ӡ��������ƨ���ϡ�\n"NOR;
        } else {
                mout = "��" + dir + "��ȥ��\n";
                min = "���˹�����\n";
        }

       if( wizardp(me) && me->query("env/invisibility") 
	&&(wiz_level(me) >= wiz_level(env)))
	{
		msg = "";
        } else
        msg = me->name() + mout;
        //message( "vision", me->name() + mout, environment(me), ({me}) );
        message( "vision", msg, environment(me), ({me}) );
        if( me->move(obj) ) {
                me->remove_all_enemy();
       if( wizardp(me) && me->query("env/invisibility") 
	&&(wiz_level(me) >= wiz_level(env)))
	{
		msg = "";
        } else
		msg = me->name() + min;
                //message( "vision", me->name() + min, environment(me), ({me}) );
        message( "vision", msg, environment(me), ({me}) );
                me->set_temp("pending", 0);
                all_inventory(env)->follow_me(me, arg);
                if( !obj->is_chatting_room() ) consume_jingli(me);//add Byp@MX 
                return 1;
        }

        return 0;
}

void do_flee(object me)
{
        mapping exits;
        string *directions;

        if( !environment(me) || !living(me) ) return;
        exits = environment(me)->query("exits");
        if( !mapp(exits) || !sizeof(exits) ) return;
        directions = keys(exits);
        tell_object(me, "�������һ���������...\n");
        main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : go <����>

������ָ���ķ����ƶ���

HELP
    );
    return 1;
}
