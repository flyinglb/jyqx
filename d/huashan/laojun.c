// laojun.c

inherit ROOM;

void create()
{
        set("short", "�Ͼ���");
	set("long", @LONG
��������Ҫ�������£�������������ЪϢ���Ͼ�����һ������೤��
ɽ�����ഫΪ̫���Ͼ����ˣ�����·��ͨ��������ϴ���ţ�����������
��������Ϊ��ɽͨ����
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "westdown" : __DIR__"pingxinshi",
            "southup"  : __DIR__"husun",
        ]));
        set("objects", ([
             __DIR__"npc/lao-denuo": 1,
        ]));

//        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}
 
int valid_leave(object me, string dir)
{
	if ((me->query("family/family_name") == "��ɽ�ɽ���") &&
		dir == "southup" &&
		objectp(present("lao denuo", environment(me))))
		return notify_fail(
"�͵�ŵȰ������ʦ�н���������إ����ǰ���뿪��ɽ�ˣ����ϲ��ǻ�ɽ�����ˡ�
�������Ϻ��ˣ���λ" + RANK_D->query_respect(me) + "������ذɡ�\n");
	return ::valid_leave(me, dir);
}
 
