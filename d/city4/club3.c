/*  <SecCrypt CPL V3R05>  */
 
//  Room:  /d/city/club3
inherit  ROOM;

void  create  ()
{
    set  ("short",  "������");
    set  ("long",  @LONG
����һ��������Ĵ������������м���һ��Բ�ε����ӡ���
���������˸��ֹ�棺�л����ģ������Ҿߵģ����������Ļ���
�Ҵ��ƴ�Ĺ�档���Ķ����������и��ţ����洫������������
�����ˣ����ȵĽ�����
LONG);

    set("light_up",  1);
    set("no_magic",  1);
    set("no_fight",  1);
    set("exits",  ([  /*  sizeof()  ==  2  */
        "down"  :  __DIR__"clubpoem",
        "north":  __DIR__"piggy",
        "south":  __DIR__"qishi",
    ]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
