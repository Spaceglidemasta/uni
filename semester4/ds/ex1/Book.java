package ex1;

public class Book extends Publication {
    
    private String isbn;
    private String author;


    Book(String title, String language, double price, String isbn, String author){
        super(title, language, price);

        this.isbn = isbn;
        this.author = author;


    }

    @Override
    public void print(){
        System.out.printf(
            """
                Title: %s
                Author: %s
                Language: %s
                Price: %f
                ISBN: %s
                    """
                , this.title
                , this.author
                , this.language
                , this.price
                , this.isbn
        );
    }

}
