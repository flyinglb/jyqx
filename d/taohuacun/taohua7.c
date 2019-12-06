// Room: /d/taohuacun/taohua7

inherit ROOM;
// #include "/cmds/std/valid_move.h";

void create ()
{
        set ("short", "ԧ��Ϫ");
        set ("long", @LONG
�������һ�Ϫ��֧��ˮ����͸������컣���Ϣ���£�����
ס�ҵľ������ڡ�ֻ�н���˵���ң����һ�ͯ����(apply)��
����ķ���(house)���������������Լ��İ�����
    �����Ѿ��м���С������ÿ������ǰ��������(paizi)��д
��Щ�˼ҵ����֡�
LONG);

        set("exits", ([ /* sizeof() == 2 */
                "east" : __DIR__"taohua6",
        ]));
        set("outdoors", 1);
        setup();
}

void init()
{
        add_action("show_name", "look");
        add_action("enter_home","",1);
}

int show_name(string arg)
{     
        mixed *files; 
        string who,result,content,chinese;
        int n,i,j,k;
        string host, host1, host2;
        int len, len1;

        if(!arg||arg!="paizi") return 0;
        files=get_dir("/data/playerhomes/");
        n=sizeof(files);
        j=0;
        for(i=0;i<=n-1;i++)
        {
               if(sscanf(files[i], "h_%s.o", who)==1)
               {
                       files[j]=who;
                       ++j;
               }
        }
        result="\n                        ������� \n";
        if (j>0)
        {
               --j;
               k=0;
               for (i=0;i<=j;i++)
               {
                   content=read_file("/data/playerhomes/h_"+files[i]+".o");
                   if(content)
                   {
                       if(sscanf(content,"%*s\"name\":\"%s\"",chinese)==2)
                       {
                           if(sscanf(content, "%*s\"home_host\":({\"%s\",\"%s\",})", host1,host2)==3)
                           {
                               if(host1==files[i]) host=host1+" & "+host2;
                               else if(host2==files[i]) host=host2+" & "+host1;
                               else host="data error";
                           } else host=files[i];
                           len=strlen(chinese);
                           len1=32-strlen(host);
                           if(len1<1) len1=1; // this should not happen.
                           if(len>len1) chinese=chinese[0..(len1-1)];
                           chinese+=" ("+capitalize(host)+")";
                           result+=sprintf("%-35s  ",chinese);
                           if(k==1) result+="\n";
                           k=1-k;
                       }
                   }
               }
        }
      
        result="\n"+result+"\n\n\n"+"ע���������ҵĵ�һ�����������롣\n";
        this_player()->start_more(result);
      
        return 1;
}

int enter_home(string arg)
{     
        string *files;
        object env,*inv,room,me=this_player();
        string roomid;
        int i;

        roomid="h_"+query_verb();
        files=get_dir("/data/playerhomes/");
        if(member_array(roomid+".o",files)==-1)
            return 0;
        //if(!valid_move(me)) return 0; 
        //check if can move. mon 9/25/97

        env=environment(me);
        inv=all_inventory(env);
        if(i=sizeof(inv))
        {
            for(i=0; i<sizeof(inv); i++)
            {
                if (inv[i]->query("id")==roomid)
                {
                    room=inv[i];
                    break;
                }
            } 
        }
        if(!room)
        {
            room=new("/d/taohuacun/obj/home");
            room->set("file_name",roomid);
            room->restore();        
            room->set("no_fight",1);
            room->set("no_magic",1);
            room->move(env);
        }
        message_vision("$N�����һ���ţ����˽�ȥ��\n",me);
        me->move(room);
        return 1;
}

int clean_up()
{      // this is special for this room. no clean_up when there are
       //player homes inside.

       object *inv;
       int i;

       inv = all_inventory();
       for(i=sizeof(inv)-1; i>=0; i--)
           if(inv[i]->is_home() || userp(inv[i])) return 1;
 
       return ::clean_up();

}
