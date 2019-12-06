// Room: /d/shaolin/twdian2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������������������Ŵ�Ħ��ʦ��������ʿ�Ļ�
���Լ�һЩ����Ԫ�ϵ��ֻ�������ɢ�ҵط���������ţ�ľ
��ȡ������˴��Ǳ��ɵ��Ӵ�������֮������λ��������ֳ�
���飬�����ô�ľ�����(nian fojing)��
LONG );
	set("exits", ([
		"east" : __DIR__"twdian",
//                "west" : "/u/simon/room/jingshi",
	]));
	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}
void init()
{
        add_action("do_nian", "nian");
}
int do_nian(string arg)
{
        object ob;
        int c_skill;
        ob = this_player();

        if (arg != "fojing") return 0;
        c_skill=(int)ob->query_skill("buddhism", 1);

        if (ob->query("jing")<40)
        {
                message_vision("$N̫���ˣ�û���������ô�ľ�㡣\n",ob);
                return 1; 
        }
        if (c_skill> 300)
        {
                message_vision("$N�����޷�ͨ����ľ���������߷�ѧ��Ϊ�ˡ�\n",ob);
                return 1; 
        }
        if (c_skill< 100)
        {
                message_vision("$N�ƺ��Է�����ò������޷����з�����߷�ѧ��Ϊ��\n",ob);
                return 1; 
        }

        message_vision("$N�ô���ľ�㡢�������ѧϰ���ķ𾭣��������ķ���������\n",ob);
        ob->improve_skill("buddhism", random(50*ob->query("int")));
        ob->receive_damage("jing", 30);
        return 1;
}


