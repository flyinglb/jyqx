//Room of wizard that haven't modify own workroom.
//Modify by Super 1998.1.2

inherit ROOM;

void create()
{
        set("short","���µĹ�����");
        set("long",@LONG
����û�н��칤���ҵ���ʦ����ʱס����������豸�ǳ��򵥣�
ֻ��һЩ������Ʒ��
LONG );
        set("exits",([ /* sizeof() == 1 */
                "north":"/d/wizard/wizard_room" ]));
        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me) )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}
