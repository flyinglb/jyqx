// topboard.c
// lingyun

#include <ansi.h>

inherit ITEM;

mapping *exp_topten =
({
        (["��1��":"��ȱ"]),(["��2��":"��ȱ"]),(["��3��":"��ȱ"]),(["��4��":"��ȱ"]),(["��5��":"��ȱ"]),
        (["��6��":"��ȱ"]),(["��7��":"��ȱ"]),(["��8��":"��ȱ"]),(["��9��":"��ȱ"]),(["��10��":"��ȱ"]),
});

string printdate = NATURE_D->game_time();

void create()
{
        string id;
        int i,exp;

        set_name(HIY"��ӹȺ����Ӣ�۰�"NOR, ({ "hero board", "board" }));
        set_weight(800);
        set("unit", "��");
        set("long","���Ǽ��ؽ�ӹȺ����Ӣ������������������԰档�������(READ)�����ġ�\n");
        set("value", 1600);
        set("material", "paper");
        set("no_get",1);
}

void init()
{
        object ob,me=this_object();

        seteuid(getuid());
        if( ob = new("/clone/topten/magic-rice") )
                if( (exp_topten=ob->query( "exp_topten" ))
                        )
                        destruct( ob );
                else
                        write(CYN"\n��ӹȺ����Ӣ�۰񱻷�ε��ˣ���֪ͨ����\n\n"NOR);
        else
                write(CYN"\n��ӹȺ����Ӣ�۰񱻷�ε��ˣ���֪ͨ����\n\n"NOR);

        add_action("do_read", "read");
}

int do_read( string arg )
{
        int i;
        string si;
        string *c_short=({"��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ","��ȱ",});
        switch( arg )
        {
                case "board":
                        write( HIC+"ʮ��������а�"+NOR+"\n" );
                        write( "��������ʮ������������£�\n" );
                        write( "--------------------------------------------------------\n" );
                        si = "����";
                        for ( i = 0; i < 10; i++ )
                        {
                                si = sprintf( "��%d��",i+1 );
                                sscanf( exp_topten[i][si],"%*s\n%s\n%*d\n",c_short[i] );
                                write( "    "+HIY"��"+chinese_number(i+1)+"��  "NOR+c_short[i]+NOR"\n" );
                        }
                        write( "========================================================\n" );
                        break;

                   default:
                        return 0;
        }
        return 1;
}
