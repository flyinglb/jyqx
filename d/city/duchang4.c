// Room: /d/city/duchang4.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "�ĳ�");
	set("long", @LONG
����Χ�ź�ѹѹ�Ķ�ͽ��ߺ��������̾����������������������Ц��������
ž��������ʹ��Ķ��伸���޷����ܣ������Ե�ǽ������һ��ֽ(paper)��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"duchang",
]));
    set("item_desc", ([
                "paper": @TEXT
    ���ӵĶķ���
    bet <����> <����> <��������>
    ���ࣺ��������������������
    ������      ��С    ��  ����������  һ��һ
    ����        �Ĵ�    ��������������  һ��һ
    ������      ��Χ��  ����������ͬ�㣩һ����ʮ��
    ��������    �ĵ���                  һ����
    ���ӣ�
    bet 0 50 silver  ѹ��ʮ��������С��
TEXT
        ]) );
	set("no_clean_up", 0);
      set("no_magic",1);
	set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/dice_thrower" : 1,
]));
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "south" && me->query_temp("gamble/amount") )
                return notify_fail("�㻹��������������߰�!\n");
        return ::valid_leave(me, dir);
}
void init()
{
        this_player()->delete_temp("gamble");
}
