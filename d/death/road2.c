// Room: /d/death/road2.c
 
inherit ROOM;
 
void create()
{
        set("short", "���Ŵ��");
        set("long", @LONG
������һ����ɭɭ��·��, ŨŨ���������������, ������
Զ������ɢȥ�Ƶ�. ����·ǰ��ֻ�������ǵļ�յ����........
 
LONG );
        set("exits", ([ /* sizeof() == 2 */
		"north" : "/d/death/road3",
		"south" : "/d/death/road1",
	]));
	set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        int i;
        if (dir == "north") {
                i = (int)me->query_temp("long_road");
                i = i + 1;
                if (i == 5) {
                me->delete_temp("long_road");
                return 1;
                }
                else {
                        me->set_temp("long_road",i);
                        return notify_fail("����������..... �������ܾ�ɫ��Ȼ��û�б�....\n");
                }
        }
        else {
        if (dir == "south") {
                me->delete_temp("long_road");
                return 1;
                }
        return 1;
        }
}
