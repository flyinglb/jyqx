// Room: /xiaoyao/yaogu.c
inherit ROOM;

void create()
{
        set("short", "ҩ��");
        set("long", @LONG
����Ѧ��ү�ӽ�����ҩ�ĺ�ɽ�������ÿһ������ÿһ�Ų���������п�
�����ܲ���ʲô����Ѧ��ү�����ﶼ�����Ǽ�ֵ���ǵı������Ĵ��Ǹ��ڹ���
��������Ȼ������ΪѦ��ү����ҩ���˲��١�
LONG );
        set("outdoors", "xiaoyao");
        set("exits", ([
                "north" : "/d/xiaoyao/muwu1",
        ]));
        set("caoyao" , 500);
        setup();
}

void init()
{
        add_action("do_dig", "wa");
}

int do_dig(string arg)
{
        object me, ob;
        string str;
        me = this_player();
        if( me->query("family/family_name") != "��ң��" ) return 0;
        if( !me->query_temp("job_xiaoyao_tool") ) return 0;
        if( !objectp(present("yao chu", me)) )
                return notify_fail("��û�й�����ô�ڣ�\n");
        if (!arg || (arg != "ҩ" && arg != "yao"))
                return notify_fail("�����ų�ͷ��֪���ô��������֡�\n");
        if(!me->query_temp("job_xiaoyao"))
                return notify_fail("����Ⱦ�������ͬ���˲�����ҩ\n");
        if( me->is_busy() )
                return notify_fail("�����һ��������û����ɡ�\n");
        if( me->is_fighting() )
                return notify_fail("��������æ�Ŵ���ء�\n");
        if( (int)me->query("jing") < 50)
                return notify_fail("���Ѿ��۵�����ͷ���ò����ˣ���ô�ڣ�\n");
        message_vision("$N����ҩ�������ⲻͣ����������......\n",me);
        me->add("jing",-(20+random(10)));
        me->start_busy(1);
        if(query("caoyao")<=0) {
                message_vision("$N����һ�ᣬ���������Ѿ�û�в�ҩ�����ˣ�\n",me);
                return 1;
        }
        if(random(16) < 2) {
                message_vision(HIY"$N�������ţ�ͻȻ������һ���ر�Ĳݣ�\n"NOR,me);
                ob = new(__DIR__"obj/caoyao");
                ob->move(me);
                environment(me)->add("caoyao",-1);
                me->delete_temp("job_xiaoyao");
                ob->set_temp("finish_id",me->query("id"));
                tell_object(me,"���ڵ���һ�ò�ҩ��\n");
        }
        if(random(20) == 1) {
                if(me->query_temp("job_xiaoyao_finish")) str ="�˷�";
                else str = "����";
                message_vision(HIG"ֻ��$N"+str+"���ȣ�����һ��$N���е�ҩ�����ˣ�\n"NOR, me);
                destruct(present("yao chu", me));
        }
        if(random(10) == 1) {
                if(me->query("combat_exp")<=5000)
                    ob = new(__DIR__"npc/bee");
                else if(me->query("combat_exp")<=10000)
                    ob = new(__DIR__"npc/monkey");
                else if(me->query("combat_exp")<=20000)
                    ob = new(__DIR__"npc/deer");
                else if(me->query("combat_exp")<=30000)
                    ob = new(__DIR__"npc/snake");
                else if(me->query("combat_exp")<=50000)
                    ob = new(__DIR__"npc/laohu");
                else {
                    ob = new(__DIR__"npc/laohu");
                    ob->set("combat_exp", 490000+random(10000));
                    ob->set_temp("apply/attack", 300);
                    ob->set_temp("apply/defense", 200);
                    ob->set_temp("apply/damage", 10);
                    ob->set_temp("apply/armor", 100);
                }
                ob->move(this_object());
                message_vision(HIR"$Nһ��С�ľ�����һ"+ob->query("unit")+
                "$n��$n�����Ƶ���$N���𹥻���\n"NOR,me,ob);
                ob->kill_ob(me);
                me->fight_ob(ob);
        }
        return 1;
}
