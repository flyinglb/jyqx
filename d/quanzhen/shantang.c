// shantang.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ȫ��̵����ã��ǵ������ò͵ĵط�������úܴ�
����ذڷ���һ��һ�ŵ����Ρ�������������������������ȫ��
���ӣ��е������òͣ��еĵ�ͷ̸Ц�����ſɿڵķ��ˣ����̲�
סҲ���(order)һ�ݡ�
LONG
        );
        set("exits",([
                "north" : __DIR__"xiuxishi",
                "east" : __DIR__"chufang",
                "northwest" : __DIR__"wuchang2",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_order","order");
}

int do_order(string arg)
{
        object me=this_player();
        object food;
        object water;

        if (arg)  return notify_fail("������������û�а���\n");
        if (me->query("family/family_name") != "ȫ���")
        {
              message_vision("�𹤵��˳����������$Nһ�ۣ������������ģ������췹�ԣ���\n",me);
              return 1;
        }

        if ((present("bowl",this_player()) || present("rice",this_player())))
              message_vision("�𹤵��˳����������$Nһ�ۣ�����û��������Ҫ����\n",me);
        else
        {
              message_vision("�𹤵�����æ�ӳ�����������һ���׷���һ��ˮ���˸�$N��\n",me);
              food=new(__DIR__"obj/rice");
              water=new(__DIR__"obj/bowl");
              food->move(me);
              water->move(me);
        }
        return 1;
}

int valid_leave(object me,string dir)
{
        me=this_player();
        if(( dir=="north" || dir=="northwest")
        && (present("bowl",this_player()) || present("rice",this_player())))
             return notify_fail("�𹤵���˵����ʳ�����ˮ���ܴ�������ȥ��\n");
        return ::valid_leave(me,dir);
}
