import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { BlogPost } from './BlogPost';

const perPage = 6;

@Injectable({
  providedIn: 'root'
})

// https://stackoverflow.com/questions/38271273/experimental-decorators-warning-in-typescript-compilation
export class PostService {

  temp : BlogPost;
  constructor(private http: HttpClient) { }

  getPosts(page, tag, category): Observable<BlogPost[]> {
    let params = {
      page: page,
      perPage: perPage.toString()
    }

    if (tag != null) {
      params["tag"] = tag;
    }

    if (category != null) {
      params["category"] = category;
    }

    return this.http.get<BlogPost[]>(`https://web422youjin.herokuapp.com/api/posts`,{ params });
  }

  getPostbyId(id): Observable<BlogPost>{
    console.log("Test:  "+id);
    return this.http.get<BlogPost>(`https://web422youjin.herokuapp.com/api/posts/${id}`);
  }

  getCategories(): Observable<any>{

    return this.http.get<any>(`https://web422youjin.herokuapp.com/api/categories`);
  }

  getTags(): Observable<string[]>{

    return this.http.get<string[]>(`https://web422youjin.herokuapp.com/api/tags`);
  }

}
