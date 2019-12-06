// home.c
// standard home for players.
// by mon. 3/3/97

#include <ansi.h>

inherit F_SAVE;
inherit ITEM;

string out="/d/taohuacun/taohua7";

int save_room();
int do_bed();
string check_str(string str);
object find_bed(object me);
void get_long_text(string str, string text);
void get_bed_long_text(string str, string text);

int is_home() {return 1;}

void create()
{
     set_name("�·�",({"room"}));
     set("short", "��׼�·�");
     set("long", @LONG

һ�ж����ú��ˣ�ֻ��һЩ����װ�ޡ�
LONG
     );
     set("home_host",({"def_host"}));
//     set("env/invisibility",1);
     set("exits", ([
       "out": out,
     ]));
     set_max_encumbrance(100000000);
//     set_max_items(20);
     set_weight(10000000);
     set("no_get",1);
//     set("no_magic", 1);
     set("no_fight", 1);
     seteuid(getuid());
     setup();

}

void init()
{
     object me=this_player(), env=this_object();
     object *present;
     string id,*home_host,*invited;
     int i,inv,j,k;

     if(env==environment(me))
     {
         set_name(this_object()->query("short"), ({this_object()->query("file_name")}));
         id=(me->parse_command_id_list())[0];
         home_host=env->query("home_host");

         if (member_array(id,home_host)==-1 && !me->query("is_baby"))
         {
             invited=me->query_temp("invited");
             inv=0;
             if(invited)
             {
                 for(i=0;i<=sizeof(invited)-1;i++)
                 {
                     if(member_array(invited[i],home_host)>-1)
                     {
                         inv=1;
                         break;
                     }
                 }
             }
             if(inv==1)
             {
                 present=all_inventory(env);
                 j=sizeof(present);
                 k=0;
                 if(j)
                 {
                     for(i=0; i<j; i++)
                     {
                         if(member_array(present[i]->query("id"),home_host)>-1)
                         {
                             k=1;
                             break;
                         }
                     }
                 }
                 if(!k)
                 {
                     write("���˲��ڼң������Ǵ���������ɡ�\n");
                     me->move(out,1);
                     tell_room(out,me->query("name")+"ʧ�������˳�����\n",({me}));
                     return;
                 }
             }
             else
             {
                 tell_object(me, "������ �������ˣ�\n");
                 tell_object(me, "ĳĳ����һ�ţ������������ƨ�� ��  \n");
                 tell_object(me, "ĳĳ����һ�ţ������������ƨ�� ��  \n");
                 me->move(out,1);
                 tell_room(out,me->query("name")+
                  "�ƺ�����һ�����˳�������ɫ�е��Ǳ���\n", ({me}));
                 return;
             }
             tell_room(env,me->query("name")+"�����ţ����˽�����\n",({me}));
         }
         add_action("do_bed", "gosleep");
         add_action("do_bed", "gobed" );
         add_action("do_bed", "bed");
         add_action("go_out", "out");
         find_bed(me);
         if (member_array(me->query("id"),home_host)>-1)
         {
             add_action("set_long", "homedesc");
             add_action("set_short", "homename");
             add_action("set_bed_long", "beddesc");
             add_action("set_bed_short", "bedname");
             add_action("do_findbaby","findbaby");
         }
     }
     return;
}

int do_findbaby()
{
//    object me=this_player(),*list,*parents,baby,where;
    object me=this_player(),*list,baby,where;
    int number,size,i,j,found;
    string myid,*babyid;

    number=me->query("child");
    if(number==0) return notify_fail("����û�����º����ء�:)\n");

    myid=me->query("id");

    list=children("/d/taohuacun/npc/baby");
    size=sizeof(list);

    for(i=1;i<=number;i++)
    {
        found=0;
        if(size>0)
        {
            for(j=0;j<size;j++)
            {
                if(list[j]->query("id")==me->query("child_"+i+"/id")[0])
                {
                    where=environment(list[j]);
                    if(where)
                    {
                        found=1;
                        write(list[j]->query("name")+"������");
                        if(where->query("short"))
                        {
                            write(where->query("short"));
                        }
                        else
                        {
                            write(where->short());
                        }
                        write("��\n");
                        break;
// If one have more than one boys or girls, break here after first match. Dream 01/03/98.
                    }
                }
            }
        }
        if(found==0)
        {
            if(me->query("child_"+i+"/id"))
            {
     //modify old baby data, for compatibility.
                if(stringp(me->query("child_"+i+"/id")))
                {
                    babyid=({me->query("child_"+i+"/id")})+({"baby"});
                    me->set("child_"+i+"/id",babyid);
                    me->save();
                }
                babyid=me->query("child_"+i+"/id");
                baby=new("/d/taohuacun/npc/baby");
                baby->set("long",me->query("child_"+i+"/long"));
                baby->set("gender",me->query("child_"+i+"/gender"));
                baby->set("parents",me->query("child_"+i+"/parents"));
                baby->set_name(me->query("child_"+i+"/name"),babyid);
                baby->move(environment(me));
                message_vision("���Ȼ����������"+
                   ({"̽��һ��С�Թ�","���һ˫С��Ѿ","���һ֧С��"})
                   [random(3)]+"������\n",me);
            }
            else
            {
                write("Error: don't have data for baby "+i+". Please report to wiz. :)\n");
            }
        }
    }
    return 1;
}

object find_bed(object me)
{
    object env,*inv,table,card,bed,home=this_object();
    string str;
    int i;
    env=environment(me);
    inv=all_inventory(env);
    if(i=sizeof(inv))
    {
        for(i=0; i<sizeof(inv); i++)
        {
            if (inv[i]->query("id")=="bed")
            {
                bed=inv[i];
                break;
            }
        }
    }

    if(!bed)
    {
        table=new(__DIR__"table");
        table->move(home);
        card=new(__DIR__"card");
        card->move(table);
        bed=new(__DIR__"bed");
        bed->set("out",this_object());
        if(strlen(str=home->query("bed_short"))>1)
        {
            bed->set("short",str);
            bed->set_name(str,({bed->query("id")}));
        }
        if(strlen(str=home->query("bed_long"))>1)
        {
            bed->set("long",str);
        }
        bed->move(home);
    }
    return bed;
}

int do_bed()
{
    object me=this_player(),bed;
    bed=find_bed(me);
    message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
    if(!me->move(bed))
    {
        write(HIY "�����Ѿ��������ˣ�\n" NOR);
    }
    else
    {
        message_vision(HIY "\nɳ������һ����$N���˽�����\n" NOR, me);
    }
    return 1;
}

string query_save_file()
{
    return DATA_DIR"playerhomes/"+this_object()->query("file_name");
}

int save_room()
{
    string file;

    file=this_object()->query_save_file();

//   if( file_size(file+".o")!=-1 ) {
//     write("�����Ѵ��ڣ�Ҫɾ���ɵ���[y/n]");
//     input_to("save_room_file");
//     return 1;
//       }
//   return save_room_file("y");
//}
//int save_room_file(string yn)
//{
//   if( strlen(yn)<1 || yn[0]!='y' ) return 1;

    write("�浵 ����������\n");
    if( save() )
    {
        write("Ok.\n");
        return 1;
    }
    else
    {
        write("��û��д�����������Ȩ����\n");
        return 0;
    }
}

int go_out()
{
    object me=this_player();
    tell_room(this_object(),me->query("name")+"�ƿ��ţ����˳�ȥ��\n",({me}));
    me->move(out);
    message_vision("$N�ƿ��ţ����˳�����\n",me);
    return 1;
}

int set_short(string str)
{
    if(!str) return 0;

    str=check_str(str);
    set("short",str);
    set_name(this_object()->query("short"), ({this_object()->query("file_name")}));
    save_room();
    return 1;
}

int set_bed_short(string str)
{   object bed;
    if(!str) return 0;

    str=check_str(str);
    if(objectp(bed=present("home_bed",this_object())) && bed->query("id") == "home_bed")
    {
        set("bed_short",str);
        bed->set("short",str);
        bed->set_name(str,({bed->query("id")}));
        save_room();
        return 1;
    }
    return 0;
}

int set_long()
{
    string str;
    this_player()->edit( (:get_long_text, str :) );
    return 1;
}

int set_bed_long()
{
    string str;
    this_player()->edit( (:get_bed_long_text, str :) );
    return 1;
}

void get_long_text(string str, string text)
{
    str=check_str(text);
    set("long",str);
    save_room();
    return;
}

void get_bed_long_text(string str, string text)
{
    object bed;

    str=check_str(text);
    set("bed_long",str);
    if(objectp(bed=present("home_bed",this_object())))
    {
        bed->set("long",str);
    }
    save_room();
    return;
}

string check_str(string str)
{
    str=replace_string(str,"\"","");
    str=replace_string(str,";","");
    str=replace_string(str,"\\","");
    str=replace_string(str,"/","");
    str=replace_string(str,"'","");
    str=replace_string(str,"`","");
    str=replace_string(str,",","");
    str=replace_string(str,"!","");
    str=replace_string(str,"~","");
    str=replace_string(str,"{","");
    str=replace_string(str,"}","");
    str=replace_string(str,"$","");
    str=replace_string(str,"&","");
    return str;
}

int clean_up()
{    //clean_up homes
    object *inv,*inv1;
    int i,j;

    if( !clonep() && this_object()->query("no_clean_up") ) return 1;

    inv = all_inventory();
    for(i=sizeof(inv)-1; i>=0; i--)
    {
        if(userp(inv[i])) return 1;
        if(inv[i]->query("if_bed"))
        {  //a bed object
            inv1=all_inventory(inv[i]);
            if(sizeof(inv1)>0)
                for(j=sizeof(inv1)-1; j>=0; j--)
                {
                    if (userp(inv1[j])) return 1;
                }
        }
    }

    destruct(this_object());
    return 0;
}
