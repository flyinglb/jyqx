// Room: /city3/tidufu.c
// Date: Feb.14 1998
inherit ROOM;

void create()
{
        set("short", "�ᶽ��");
        set("long", @LONG
��������ᶽ���˰칫�µĵط�����ǰ�� (front)����ľ����
�����������ŵģ����ǳɶ��ᶽ����¡�����վ���Ʒ粻����������
�ױ��̴ӣ�����ȥ��ʮ�ֱ뺷��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"tidugate",
        ]));
        set("objects", ([ /* sizeof() == 1 */
             __DIR__"npc/wutiande" : 1,
             __DIR__"npc/shicong"  : 2,
             __DIR__"npc/qinbing" : 4,
        ]));
        set("item_desc",([
            "front" : "
                ###########################
                #                         #
                #    ��   ��   ��   ��    #
                #                         #
                ###########################
                            !~A~!
                      @~~~~~!(O)!~~~~~@
                           (.@ @.)
                            . ~ .
                         /   ~.�����̵�...�������...��������? ���ϵ���ү��? ...
                        #           #
             HHHH     #               #
             HHHH   #    n         n    #
          |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
           ```````````````````````````````````````
                  ()                      ()
                 ()                        ()
                ()                          ()
               ()                            ()\n"
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
