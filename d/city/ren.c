//Room of wizard that haven't modify own workroom.
//Modify by Super 1998.1.2

inherit ROOM;

void create()
{
        set("short","����С��");
        set("long",@LONG
���Ǹ�����Ǹ��������ĵط�,������:ren ������ Ӣ����
ֻ��һЩ������Ʒ��
LONG );
        set("exits",([ /* sizeof() == 1 */
		"down" : "/d/city/wumiao",
	]));
	set("objects", ([
            __DIR__"npc/winzip" : 1,
	]));
        set("no_fight", 1);
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me) )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}
