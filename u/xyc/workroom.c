//Room of wizard that haven't modify own workroom.
//Modify by Super 1998.1.2

inherit ROOM;

void create()
{
        set("short","��ʦ�Ĺ�����");
        set("long",@LONG
���������ʦ�ļ��ˡ���ľ�����ļ�˽ʹ�����������Եù�ɫ��
LONG);
        set("exits",([ /* sizeof() == 1 */
                "down" : "/d/city/chaguan3",
                "north":"/d/wizard/wizard_room" ]));
        set("objects", ([
                __DIR__"biaotou" : 1,
        ]));
        set("valid_startroom", 1);
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me) )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}
