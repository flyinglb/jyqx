//Room of wizard that haven't modify own workroom.


//inherit CHATTING_ROOM;
inherit ROOM;

void create()
{
        set("short","���䳡");
        set("long",@LONG
����û�н��칤���ҵ���ʦ����ʱס����������豸�ǳ��򵥣�
ֻ��һЩ������Ʒ��
LONG );
        set("exits",([ /* sizeof() == 1 */
                "west":__DIR__"workroom",
                "south":__FILE__,
                "down":"/d/city/guangchang" ]));
        set("valid_startroom", 1);
        set("objects", ([
                "/d/baituo/npc/tong-ren" : 5,
                "/d/npc/tong-ren" : 5,
                "/clone/food/jitui" : 5,
                "/clone/food/jiudai" : 2,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/gangdao" : 1,
                "/clone/weapon/changbian" : 1,
                "/clone/weapon/gangzhang" : 1,
                "/clone/weapon/qimeigun" : 1,
                "/clone/weapon/gangjia": 1,
                "/d/city/obj/tiefu": 1,
                "/d/xiangyang/npc/obj/mujian": 1,
                "/d/xiangyang/npc/obj/mudao": 1,
                "/d/xiangyang/npc/obj/mugun": 1,
        ]));
        setup();
        set("sleep_room", 1);
}
int valid_leave(object me, string dir)
{
        if( dir=="south" ) {
                me-> receive_damage ("qi",10) ;
                me-> receive_wound  ("qi",10) ;
                write(HIR"ͻȻһ���������Ϯ������һ��С�ı������˼��¡�\n"NOR);
        }
        return ::valid_leave(me, dir);
}
