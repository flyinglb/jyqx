// ����
inherit ITEM;

void create()
{
        set_name("����", ({"jiaxin", "paper"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"������Ľ�ݸ�д��Ľ�ݲ��ļ��飬������Ҫ�����·����������˸У�\n"
"��ϣ��Ľ�ݲ����ճ�����Ϊͽ��\n");
                set("material", "paper");
        }
}


