// Room: /d/village/temple1.c

inherit ROOM;

void create()
{
        set("short", "��̳��");
	set("long", @LONG
����һ��ʮ���ƾɵ�С�����﹩������������̳�������Ѿ��ܲ���
�ˣ�����Ҳ���˺ܶ೾�����������кܾ�û������������ˡ���Ŵ���
ƶ����̫�ã��Ѳ��ټ���춲���ү�����������ˡ����������ǽ���и���
�˶�ߵĶ�(hole)��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "southwest" : __DIR__"nwroad1",
        ]));
        set("item_desc", ([
                "hole": "��������󶴱����俪���ã����Ǳߺ����и�С���ӡ�\n"
        ]) );
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_enter", "enter");
}
int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="hole" ) {
		if( me->query_temp("marks/��") ) {
		        message("vision",
me->name() + "һ�������������˽�ȥ��\n",
			environment(me), ({me}) );
                        me->move("/d/village/temple2");
                        message("vision",
me->name() + "�Ӷ������˽�����\n",
                        environment(me), ({me}) );
		return 1;
		}
		else {
                        write("��û�����ᰮ�궴��?!\n");
                        return 1;
                }
	}
}	

