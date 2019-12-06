// Room: /xiaoyao/yaogu.c
inherit ROOM;

void create()
{
        set("short", "�߿�");
        set("long", @LONG
���������߷紫���߿��ˣ�����ɽ���ӵ����߱�����ؤ����ڶ�
��̾���硣��������߸��Ǽ���δ��������δ���ˣ�
LONG );
        set("outdoors", "xiaoyao");
        set("exits", ([
                "west" : "/d/baituo/sheku1",
        ]));
        setup();
}

void init()
{
        add_action("do_wei", "wei");
}

int do_wei(string arg)
{
        object me;
        me = this_player();
        if( me->query("family/family_name") != "����ɽ��" ) return 0;
        if( !me->query_temp("job_btshan_tool") ) return 0;
        if( !objectp(present("she liang", me)) )
                return notify_fail("û��������ôι�������Լ�ι����^_^\n");
        if (!arg || (arg != "��" && arg != "she"))
                return notify_fail("ֻ��Ⱥ��ӼӼ���㾹��֪��ôι��\n");
        if(!me->query_temp("job_btshan"))
                return notify_fail("˭ ����������ģ�����\n");
        if( me->is_busy() )
                return notify_fail("�����������ż�������\n");
        if( (int)me->query("qi") < 40)
                return notify_fail("���Ѿ���Ŭ���ˣ���Ϣһ��ɣ�\n");
          message_vision("$N�������ĵ�������������ʼι������������\n",me);
        me->add("qi",-(20+random(10)));
        me->start_busy(1);
        if(random(18) < 2) {
        message_vision(HIY"$N���ڰ��߸�ι���ˣ������Ϲ˽����ˣ�\n"NOR,me);
                me->delete_temp("job_btshan");
        destruct(present("she liang", me));
        me->delete_temp("job_btshan_tool");
                me->set_temp("finish_id",1);
                tell_object(me,"���Ѿ���������񣡿��Ի�ȥ�����ˡ�\n");
        }
        if(random(20) == 1) {
              message_vision(HIG"��Ⱥ��������ι��������ι���ˣ���û�Ա���\n"NOR, me);
                destruct(present("she liang", me));
        }
        if(random(15) == 1) {
                message_vision(RED"һ��������ͻȻ����ҧ��һ�ڣ�\n"NOR, me);
                tell_object(me, HIG "��ֻ����һ��ѣ�Σ������ж��ˣ�\n" NOR );
                this_player()->apply_condition("snake_poison", 30);
                message_vision(HIY"����ȥ���Ϲ˰ɣ�\n"NOR, me);
        }
        return 1;
}
