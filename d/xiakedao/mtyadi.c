// mtyadi.c �µ�

inherit ROOM;

int do_climb(string arg);
void create()
{
        set("short", "�µ�");
        set("long", @TEXT
�����ǰ��һ����ֱ��ɽ�壬����ǧ�ɣ��嶥����������Լ��
����ɽ���ͺͺ�ģ����������㴦��ɽ�崹��һ������(lian)����
ϸһ�������������⼣���ƺ�����������������.
TEXT );
        set("outdoors", "xiakedao");
        set("exits", ([
            "north" : __DIR__"mtroad",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
        int n;
        n = this_player()->query_skill("dodge",1);
        if ( !arg || arg != "lian")
        {
            write("��Ҫ��ʲôѽ? \n");
            return 1;
        }
message_vision("$N������һ����������������������������\n", this_player());
        if(n >80){
message_vision("$N���˰��죬����������ȥ��$N���˵Ĳ�������������\n", this_player());
            this_player()->move(__DIR__"mtdating");
        }
        else
        {
message_vision("$N����һ�ᣬһ��С��ˤ��������\n", this_player());
            this_player()->receive_damage("qi",50);
            this_player()->receive_wound("qi",50);
        }
        return 1;
}
