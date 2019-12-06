// Room: room64.c
inherit ROOM;
void create()
{
        set("short", "����ɽ");
        set("long", @LONG
����������ֻ�з紵���Σ�������ɣ����Ӳ��죬ע��Ⱥɽ�����˲�����Ȼ
����˼��֮���飡��ǰ����ֻ��һ�����ң����پ��£����¿����ͱ��絶������
����ӿ������ס�
LONG
        );
        set("exits", ([
  "north" : __DIR__"room61",
]));

        set("outdoors", "room64");
    setup();
}

void init()
{
   add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object me,room;
        me = this_player();
        if( !arg || arg!="down") return notify_fail("��Ҫ��������\n");          
        message_vision("$N��ԥ��һ�£�����������������ȥ��\n",me);

        if ((int)me->query_skill("dodge",1) < 300 ) {
                        message("vision",me->name()+"��������׹ȥ���������׶༪����!\n", environment(me), ({me}) );
                        if (!room=find_object(__DIR__"room66"))
                        room=load_object(__DIR__"room66");
                        me->move(room);
                        message("vision","�飡��һ���˵���������\n", room,({me}));
                        me->set_temp("die_for","���¾���ˤ");
                        me->die();
                        return 1;
                }

           if (random(100)>50){ 
            if (!room=find_object(__DIR__"room66"))
              room=load_object(__DIR__"room66");
       }else{
                if (!(room=find_object(__DIR__"room75")))
                  room=load_object(__DIR__"room75");
           }

           me->move(room);
           message("vision","�飡��һ���˵���������\n", room,({me}));
           return 1; 
}

