// Room: /u/zqb/tiezhang/shishi.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
      ����һ����ɽ������ɵ�Сʯ�ݣ��м���һ��ʯ�������ϰڷ��� 
һյ�͵ƣ�ɢ����������ƵĹ���������һ�ǵĵ��ϣ����źܶ�ɲݣ�����
����һ���ˡ��������£���ȥ���ݣ������������ͣ����ϴ���һ�������� 
�Ƶĺ��£�˵�����Ĺ������ء�
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "eastup" : __DIR__"shijie-3",
]));
    set("objects", ([
        __DIR__"npc/sgjn" : 1,
    ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

