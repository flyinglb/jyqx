// xin.c

inherit ITEM;

void create()
{
        set_name("����", ({"guiyun shuxin", "shu xin", "xin"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ��½��Ӣд������������ׯ�����š�\n");
//		set("no_drop", "�������������뿪�㡣\n");
                set("material", "paper");
        }
}

