// 竹筒

inherit ITEM;

varargs int destruct_she(object obj, object me, int f);
string disply_long();

void create()
{
        set_name("竹筒", ({"zhu tong", "tong"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",(: disply_long :));
                set("unit", "个");
        }
}

void init()
{
        if(environment()!=this_player()) return;
        add_action("do_get","get");
        add_action("do_put","put");
}

int do_put(string arg)
{
        string item, in_where;
        object obj, me;
        if( !arg || sscanf(arg,"%s in %s",item,in_where)!=2 ) return 0;//命令分解
        if( item != "jinshe" && item != "yinshe" ) return 0;//如果不是放蛇返回 0
        if( in_where != "zhu tong" && in_where != "tong" ) return 0;//如果不是放到竹筒返回 0
        me = this_player();
        if( !obj = present(item,me) )//如果蛇不在身上
                obj = present(item,environment(me));//就在环境里找
        if( !obj ) return notify_fail("你要放什么？\n");//如果没有找到对象
        if( query("have_she/"+item) ) //如果竹筒里已经有蛇
                return destruct_she(obj,me);//破坏掉蛇

        //错误判断结束，开始正题
        set("have_she/"+item,1);//做有蛇标记
        message_vision("$N将"+obj->name()+"放进了竹筒里。\n",me);
        return destruct_she(obj,me,1);//破坏掉蛇
}

int do_get(string arg)
{
        string item, from;
        object obj, me;
        if( !arg || sscanf(arg,"%s from %s",item,from)!=2 ) return 0;//命令分解
        if( item != "jinshe" && item != "yinshe" ) return 0;//如果不是放蛇返回 0
        if( from != "zhu tong" && from != "tong" ) return 0;//如果不是放到竹筒返回 0
        if( !query("have_she/"+item) ) //如果竹筒里没有有蛇标记
                        return notify_fail("你要拿什么？\n");
        //错误判断结束，开始正题
        obj = new(__DIR__+item);//载入对象
        me = this_player();
        obj->move(environment(me));
        delete("have_she/"+item);//删除有蛇标记

        message_vision("$N把"+obj->name()+"从竹筒里拿了出来。\n",me);
        return 1;
}

varargs int destruct_she(object obj, object me, int f)
{
        if( !f ) {
                message_vision("$N将"+obj->name()+"放进了竹筒里。\n"
                +"只见哪蛇一进去就乱咬一通，不一会筒里的蛇就都死了。\n",me);
                delete("have_she");//删除有蛇标记
        }
        obj->move(VOID_OB);
        destruct(obj);
        return 1;
}

string disply_long()
{
        string str = "这是个老竹子做成的竹筒。\n";
        if( !query("have_she/jinshe") && !query("have_she/yinshe"))
                str += "这里面是空的。\n";
        else {
                str += "这里面有：";
                if( query("have_she/jinshe") > 0)
                        str += "\t一条"+HIY+"金色血蛇\n"+NOR;
                if( query("have_she/yinshe") > 0)
                        str += "\t一条"+HIW+"银色血蛇\n"+NOR;
                str +="\n";
        }
        return str;
}
