// room: dong-2.c
// zqb


inherit ROOM;



void create()
{
        set("short", "ɽ��");
        set("long", @LONG
    һ���������ɽ�����ڳ�����һ���������ס������ʯ����������
̦޺����������ʪ�ֻ�����ʯ���ƺ����˹�����ģ������ܵ�ʯ�������ܿ�
������ĺۼ�����վ�����һ�ɿ־���Ȼ�������ƺ�������ʱ���ᱻ��Ƭ
�ڰ����ɵ���
LONG
        );
        set("exits", ([
            "out" : __DIR__"dong-1",
            "enter" : __DIR__"dong-3",
]));

        set("objects", ([
               
        ]));

        set("no_clean_up", 0);

        setup();
        //replace_program(ROOM);
}



int valid_leave(object me, string dir)
{
 if ((dir != "enter") && (dir != "out"));
 if (dir == "enter"){
            me->receive_damage("qi", 200);       
            write("��о�����ʮ�ֵĳ��ơ�\n");
    }

 if (dir == "out"){
            me->receive_damage("qi", 200);       
            write("��о�����ʮ�ֵĳ��ơ�\n");
}
return 1;
}
