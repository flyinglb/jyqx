// niupidai.c ţƤ��

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("ţƤ��", ({"niu pidai", "pidai","dai","skin" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "��������װ���Ͳ��ţƤ����ɢ�������������㡣\n");
                set("unit", "��");
                set("value", 150);
                set("max_liquid", 10);
        } 
 
        set("liquid", ([ 
                "type": "suyou cha", 
                "name": "���Ͳ�", 
                "remaining": 10, 
                "drunk_supply": 20, 
        ])); 

}
